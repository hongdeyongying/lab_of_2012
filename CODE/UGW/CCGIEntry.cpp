// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CCGIEntry.h"

#include "CDebugCgiIO.h"
#include "CFastCgiIO.h"
#include "CCommonCgiIO.h"


#include "CCheckerFactory.h"
#include "CConvertorFactory.h"
#include "CTransactionFactory.h"


#include "CMyDispatcher.h"

#include "CDigitalSignatureFactory.h"


//##ModelId=4C10B53902C2
void MyCGI::CCGIEntry::Start(int argc,char ** argv)
{
	//分析命令行参数
	m_ci.Parse(argc,(const char **)argv);
	
	
	if(m_ci.GetArgVal("debug") == "on") // DEBUG CGI
	{
		//sSERVICE_CONFIGFILE_PATH = m_ci.GetArgVal("service");
		//sELEMENT_CONFIGFILE_PATH = m_ci.GetArgVal("element");
		sCONFIGFILE_PATH = m_ci.GetArgVal("config");
	//加载配置文件	
		//m_Config.LoadService(sSERVICE_CONFIGFILE_PATH);
		//m_Config.LoadElement(sELEMENT_CONFIGFILE_PATH);
		m_Config.Clear();m_Config.LoadConfig(sCONFIGFILE_PATH);
	//初始化日志器
		InitLoger();
		
		Start_Debug();
		
		ClearLoger();
	}
	else if(FCGX_IsCGI())   // COMMON CGI
	{				
	//加载配置文件	
		//m_Config.LoadService(sSERVICE_CONFIGFILE_PATH);
		//m_Config.LoadElement(sELEMENT_CONFIGFILE_PATH);
		m_Config.Clear();m_Config.LoadConfig(sCONFIGFILE_PATH);
	//初始化日志器
		InitLoger();
	
		Start_Common();
		ClearLoger();
	}
	else //  FAST CGI 
	{
			
		Start_Fast();
	}
}

//##ModelId=4C10B5920304
void MyCGI::CCGIEntry::Start_Common()
{		
	DEBUG_LOGER<< "Start_Common "  << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	try
	{
		m_mInPara.clear();
		m_mOutPara.clear();

		if(NULL == m_pCCgiIO)
			m_pCCgiIO = new CCommonCgiIO;
			
		if(NULL == m_pCgicc)
			m_pCgicc = new cgicc::Cgicc(m_pCCgiIO);
	
	// 1.根据启动模式，读取输入参数		
	// 2.检查输入参数格式
		GetInput();
		
		CheckFormat();
		
		DoTranslate();
	// 3.验证输入请求有效性，完整性
		CheckIntegrality();
	// 4.检查发起方的权限
		CheckPopedom();
	// 5.检查发起方的请求频次
		CheckFrequence();
	// 6.调用相关服务
		CommitTrans() ;
		
	// 7.组织输出数据//检查输出串: M  thow CMyException
		ValidOutput();
		
		TranslateOutput();
		
		
	// 8. 验证输出结果完整性	
		CheckIntegrality(false);
	
		SignOutput();
	
		
	}
	catch(MyUtility::CMyException & exp)
	{
		ERROR_LOGER << exp.ToString() << LOGER_ETAG ;
		MyUtility::CStringVector sv;

		//retcode
		sv.push_back(MyUtility::CBaseEncode::ULongToString(exp.GetErrcode()));
		m_mOutPara["retcode"] = sv;
		//retmsg
		sv[0] = exp.GetUserMsg();
		m_mOutPara["retmsg"] = sv;
		//reason
		sv[0] = exp.GetReason();
		m_mOutPara["reason"] = sv;
		//debug
		sv[0] = exp.GetDebug();
		m_mOutPara["debug"] = sv;
		
		
	}
	
	try
	{
	// 8.输出（xml、html、redir等）
		SetOupt();
	}
	catch(MyUtility::CMyException & exp)
	{
		//cout << "Content\r\n\r\n" ;
		ERROR_LOGER << exp.ToString() << LOGER_ETAG ;
	}
	
	if(NULL != m_pCCgiIO)
	{		
		delete m_pCCgiIO; 
		m_pCCgiIO = NULL;
	}
	
	if(NULL != m_pCgicc)
	{
		delete m_pCgicc; 
		m_pCgicc = NULL;
	}
	
}

//##ModelId=4C10B5C0021E
void MyCGI::CCGIEntry::Start_Fast()
{
	//加载配置文件	
		//m_Config.LoadService(sSERVICE_CONFIGFILE_PATH);
		//m_Config.LoadElement(sELEMENT_CONFIGFILE_PATH);
		m_Config.Clear();m_Config.LoadConfig(sCONFIGFILE_PATH);
	//初始化日志器
		InitLoger();
	
	DEBUG_LOGER<< "Start_Fast"  << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	static int iRequest_Times = 0,iMax_Times = 0;

	std::string sReload_config("false");

	try
	{
		iMax_Times = MyUtility::CBaseEncode::StringToInt(m_Config.GetService("_fastcgi_config").GetVarVal("max_times"));
		sReload_config = m_Config.GetService("_fastcgi_config").GetVarVal("reload_config");
		DEBUG_LOGER<< "max limit for fastcgi "  << iMax_Times<< LOGER_ETAG;
	}
	catch(...)
	{
		DEBUG_LOGER<< "No max limit for fastcgi"<< LOGER_ETAG ;
		iMax_Times = 0;
	}
	
	FCGX_Request request;

	FCGX_Init();
	FCGX_InitRequest(&request, 0, 0);

	while(FCGX_Accept_r(&request) == 0) 
	{
		iRequest_Times++;
		DEBUG_LOGER<< "times = " << iRequest_Times << "/"  << iMax_Times<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		m_pCCgiIO = new CFastCgiIO(request);
		m_pCgicc  = new cgicc::Cgicc (m_pCCgiIO);

		Start_Common();
		
		FCGX_Finish_r(&request);


		
		if((iMax_Times != 0) && ( iRequest_Times >= iMax_Times))
		{
			//ClearLoger();
			break;
		}
		else
		{			
			if(sReload_config == "true" )
			{
			//加载配置文件	
				//m_Config.LoadService(sSERVICE_CONFIGFILE_PATH);
				//m_Config.LoadElement(sELEMENT_CONFIGFILE_PATH);
				m_Config.Clear();m_Config.LoadConfig(sCONFIGFILE_PATH);
				try
				{
					iMax_Times = MyUtility::CBaseEncode::StringToInt(m_Config.GetService("_fastcgi_config").GetVarVal("max_times"));
					sReload_config = m_Config.GetService("_fastcgi_config").GetVarVal("reload_config");
					DEBUG_LOGER<< "max limit for fastcgi "  << iMax_Times << " " << sReload_config << LOGER_ETAG;
				}
				catch(...)
				{
					DEBUG_LOGER<< "No max limit for fastcgi" << LOGER_ETAG;
					iMax_Times = 0;
				}
			
			}
		}
		
	}
	//初始化日志器
		ClearLoger();
		//InitLoger();
}

//##ModelId=4C10B5CE00C7
void MyCGI::CCGIEntry::Start_Debug()
{
	DEBUG_LOGER << "\tStart_Debug" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	INFO_LOGER<<"args.file=" << m_ci.GetArgVal("file")<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
	INFO_LOGER<<"args.request=" << m_ci.GetArgVal("request")<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
	INFO_LOGER<<"args.service=" << m_ci.GetArgVal("config")<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
	//INFO_LOGER<<"args.element=" << m_ci.GetArgVal("element");//<< log4cpp::CategoryStream::ENDLINE;
	INFO_LOGER<<"args.debug=" << m_ci.GetArgVal("debug")<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	std::string  file = m_ci.GetArgVal("file");
	std::string  request = m_ci.GetArgVal("request");	
	
	m_pCCgiIO = new CDebugCgiIO(file,request);
	m_pCgicc  = new cgicc::Cgicc (m_pCCgiIO);
	
	Start_Common();
			
}

//##ModelId=4C11A65A01C8
void MyCGI::CCGIEntry::GetInput() throw(MyUtility::CMyException)
{
	DEBUG_LOGER << "\tGetInput" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	
	//表单项
	cgicc::const_form_iterator iter;

	for(iter = m_pCgicc->getElements().begin();
		iter != m_pCgicc->getElements().end();
		iter++)
	{
		INFO_LOGER<< iter->getName() << " : " << iter->getValue()<< LOGER_ETAG ;//<< log4cpp::CategoryStream::ENDLINE;
		m_mInPara[ iter->getName()].push_back(iter->getValue());
	}


	// 如果有文件
	cgicc::const_file_iterator iterFile;
	for(iterFile = m_pCgicc->getFiles().begin();
		iterFile != m_pCgicc->getFiles().end();
		iterFile++)
	{
		INFO_LOGER<<"id:"<< iterFile->getName() 
			<< " file:" << iterFile->getFilename() 
			<< " type:" << iterFile->getDataType()
			<< " length:"<< iterFile->getDataLength()<< LOGER_ETAG ;
			//<< " data:\r\n" << iterFile->getData()<< "\r\n";//<< log4cpp::CategoryStream::ENDLINE;

		m_mInPara[iterFile->getName()].push_back(iterFile->getFilename());
		m_mInFileData[iterFile->getName()].push_back(iterFile->getData());
		
	}

	// env
	MyUtility::CStringMap::const_iterator iterEnv;
	for(iterEnv= this->m_pCCgiIO->GetEnv().begin();
		iterEnv != this->m_pCCgiIO->GetEnv().end();
		iterEnv++)
	{
		INFO_LOGER<< "env." << iterEnv->first << " : " << iterEnv->second<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		m_mInEnv[iterEnv->first ] = iterEnv->second;
	}

	// post data
	if(m_mInEnv["REQUEST_METHOD"] == "post" || m_mInEnv["REQUEST_METHOD"] == "POST")
	{
		m_mInEnv["_RAW_POST_DATA"] =  m_pCgicc->getEnvironment().getPostData();
		INFO_LOGER<< "_RAW_POST_DATA" << " : " << m_mInEnv["_RAW_POST_DATA"] << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
		
	}
		
	//cookie
	const std::vector<cgicc::HTTPCookie> &cks = m_pCgicc->getEnvironment().getCookieList();

	std::vector<cgicc::HTTPCookie>::const_iterator  iterCookie = cks.begin();

	for(;iterCookie != cks.end() ; iterCookie++)
	{
		INFO_LOGER<<"cookie :"<< iterCookie->getName() 
			<< " = " << iterCookie->getValue() << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		m_mInCookie[iterCookie->getName() ] = iterCookie->getValue();
	}

	

	// default para ，配置文件中配置，以此支持不带tid 根据路径名直接进入服务tid method
	if(m_Config.IsExistService("_default_entrance"))
	{
		const MyConfig::CParameterVectorMap & mvPara = m_Config.GetService("_default_entrance").GetParameterVectorMap();

		MyConfig::CParameterVectorMap::const_iterator iterConfPara = mvPara.begin();

		for(iterConfPara;iterConfPara != mvPara.end();iterConfPara++)
		{

			if(m_mInPara.find(iterConfPara->first) == m_mInPara.end())
			{
				MyConfig::CParameterVector::const_iterator iterv = iterConfPara->second.begin();

				for(iterv;iterv != iterConfPara->second.end();iterv++)
				{
					if((iterv->GetInExistMode() == "M") && (iterv->GetDefault() != "null"))
					{
						//
						std::string default_val = iterv->GetDefault();

						//支持变量$APLICATION$
						CStringVector sv,sv1;
						sv.Split(m_mInEnv["REQUEST_URI"],"?",false);
						sv1.Split(sv[0],"/\\",false);
						
						if(default_val == "$APPLICATION$")
						{
							default_val = sv1[sv1.size() -  1];
						}

						DEBUG_LOGER<<"conf para   :"<< iterConfPara->first << " = "<< default_val<< LOGER_ETAG;
						
						m_mInPara[iterConfPara->first].push_back(default_val);
					}
				}
			}
		}
	}
	
	
}

//##ModelId=4C11A49B0096
bool MyCGI::CCGIEntry::CheckFormat() throw(MyUtility::CMyException)
{
	bool result =  false;
	
	DEBUG_LOGER <<  LOGER_ETAG;

	//输入字符串
//	cgicc::const_form_iterator iter;
	MyUtility::CStringVectorMap::const_iterator iter;


	for( iter = m_mInPara.begin();
		iter != m_mInPara.end();
		iter++)
	{
		//*debugLoger
			DEBUG_LOGER<<  iter->first << " : " << iter->second.size() << " " <<   iter->second.at(0)<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
		//DEBUG_LOGER
		std::string fmt,chker,desc,method(sCHECKER_METHOD_SINGLE);

		try
		{
			fmt = this->m_Config.GetElement(iter->first).GetFormat();
			chker = this->m_Config.GetElement(iter->first).GetChecker();	
				MyUtility::CStringVector v;
				v.Split(chker,":");
				if(v.size() == 2)
				{
					chker = v[0];
					method = v[1];
				}
			desc = this->m_Config.GetElement(iter->first).GetDesc();
		}
		catch(MyUtility::CMyException & exp)
		{
			INFO_LOGER<< "Notice : " << exp.ToString() << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
			std::string sIolist_type = m_Config.GetService("_element_config").GetVarVal("io_list");

			if(sIolist_type == "loose" )
				continue;
			else	
				throw(MyUtility::CMyException("Error: Not Installed Checker - " + chker,iPREPARE_CONFIG_ERROR) );
			
		}
	
		DEBUG_LOGER << chker << " " << method <<  LOGER_ETAG;

		std::string sigleton_flag ("");

		try
		{
			sigleton_flag = m_Config.GetService("_check_config").GetVarVal(chker);
		}
		catch(...)
		{
			LOGER_ERROR << "get _check_config error " << LOGER_ETAG;	
		};

		

		CChecker * pChecker = NULL;
		DEBUG_LOGER << chker << " " << method <<  LOGER_ETAG;

		if(sigleton_flag == "singleton")
		{
			pChecker = MyCGI::g_CCheckerFactory.GetSingletonInstance(chker);
		}
		else
		{
			pChecker = MyCGI::g_CCheckerFactory.GetInstance(chker);
		}

		if(NULL == pChecker)
		{
			LOGER_ERROR << "create checker error " << chker << " " << sigleton_flag  << LOGER_ETAG;	
			
			throw(MyUtility::CMyException("Error: Not Installed Checker - " + chker,iPREPARE_CONFIG_ERROR) );
		}
		
		DEBUG_LOGER << chker << " " << method <<  LOGER_ETAG;
		
		if(method ==sCHECKER_METHOD_SINGLE)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				DEBUG_LOGER << chker << " " << method << " " << fmt << " " << iter->second[i] <<  LOGER_ETAG;

				result = pChecker->DoSingle(iter->second[i],fmt);

				if(!result)  break;
				
			}
		}
		else if(method ==sCHECKER_METHOD_COMPLEX)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				result = pChecker->DoComplex(iter->second,m_mInPara,fmt);
			}
		}
		else
			;
		if(sigleton_flag != "singleton")
		{
			delete pChecker;pChecker = NULL;
		}
		
		if(!result)
		{		
			INFO_LOGER<<"Error Format " << desc << LOGER_ETAG;
			throw(MyUtility::CMyException(desc,iINPUT_FORMAT_ERROR));
		}

		
	}

		
	
	

	return result;
}

//##ModelId=4C11A70E02CB
bool MyCGI::CCGIEntry::CheckIntegrality(bool request) throw(MyUtility::CMyException)
{
	bool result =  true;
	
	DEBUG_LOGER << "\tCheckIntegrality : "  <<  request<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	const MyConfig::CService &servic = m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name));

	const MyConfig::CParameterVectorMap &paramap = servic.GetParameterVectorMap();

//检查参数要求必填和必空的IO参数，是否符合
	MyConfig::CParameterVectorMap::const_iterator iterpara;

	for(iterpara = paramap.begin();
		iterpara != paramap.end();
		iterpara++)
	{
		if(request)
		{
			if((iterpara->second.at(0).GetInExistMode() == "M") && (m_mInPara.find(iterpara->first) == m_mInPara.end()))
			{
				throw(MyUtility::CMyException("Lack in parameter M:" + iterpara->first + iterpara->second.at(0).GetDesc(),iINPUT_ELEMENT_LACK));
				result =  false;
				break;
			}
			else if((iterpara->second.at(0).GetInExistMode() == "B") && (m_mInPara.find(iterpara->first) != m_mInPara.end()))
			{
				throw(MyUtility::CMyException("More in parameter B:" + iterpara->first + iterpara->second.at(0).GetDesc(),iINPUT_ELEMENT_MORE));
				result =  false;
				break;
			}
				
		}
		else
		{
			if((iterpara->second.at(0).GetOutExistMode() == "M") && (m_mOutPara.find(iterpara->first) == m_mOutPara.end()))
			{
				throw(MyUtility::CMyException("Lack out parameter M:" + iterpara->first + iterpara->second.at(0).GetDesc(),iOUTPUT_ELEMENT_LACK));
				result =  false;
				break;
			}
			else if((iterpara->second.at(0).GetOutExistMode() == "B") && (m_mOutPara.find(iterpara->first) != m_mOutPara.end()))
			{
				throw(MyUtility::CMyException("More out parameter B :" + iterpara->first + iterpara->second.at(0).GetDesc(),iOUTPUT_ELEMENT_MORE));
				result =  false;
				break;
			}
		}
	}

//检查可选参数项是否都在列出的参数列表中	
	if(request)
	{
		std::string _request_integrality("strict");
		_request_integrality = servic.GetVarVal(sINTEGRALITY_CHECK_REQUEST);

		DEBUG_LOGER << "\tCheckIntegrality : " <<sINTEGRALITY_CHECK_REQUEST << "=" <<  _request_integrality<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		if(_request_integrality != ("loose") )
		{
			
		
			MyUtility::CStringVectorMap::const_iterator iterIn = m_mInPara.begin();
			for(iterIn;iterIn!=m_mInPara.end();iterIn++)
			{
				if(paramap.find(iterIn->first) == paramap.end())
				{
					throw(MyUtility::CMyException("More in parameter O:" + iterIn->first ,iINPUT_ELEMENT_MORE));
					result =  false;
					break;
				}
			}
		}
	}
	else
	{
		std::string _response_integrality("strict");
		_response_integrality = servic.GetVarVal(sINTEGRALITY_CHECK_RESPONSE);
		DEBUG_LOGER << "\tCheckIntegrality : " <<sINTEGRALITY_CHECK_RESPONSE << "=" <<  _response_integrality<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		if(_response_integrality != ("loose") )
		{
			MyUtility::CStringVectorMap::const_iterator iterOut = m_mOutPara.begin();
			
			for(iterOut;iterOut!=m_mOutPara.end();iterOut++)
			{
				if(paramap.find(iterOut->first) == paramap.end())
				{
					throw(MyUtility::CMyException("More out parameter O:" + iterOut->first ,iOUTPUT_ELEMENT_MORE));
					result =  false;
					break;
				}
			}
		}
	}
//验证请求参数签名
	if(request)
	{
		std::string sRequestVerifier = servic.GetVarVal(sRESERVED_VAR_NAME_REQUEST_VERIFY);

		std::string sigleton_flag ("");

		try
		{
			sigleton_flag = m_Config.GetService("_signature_config").GetVarVal(sRequestVerifier);
		}
		catch(...){};
		CDigitalSignature * pCDigitalSignature =NULL;
		if(sigleton_flag == "singleton" )
		{
			pCDigitalSignature = g_CDigitalSignatureFactory.GetSingletonInstance(sRequestVerifier);
		}
		else
		{
			pCDigitalSignature = g_CDigitalSignatureFactory.GetInstance(sRequestVerifier);		
		}

		if(NULL != pCDigitalSignature)
		{
			MyUtility::CStringVector  right;

			MyConfig::CVariableVectorMap::const_iterator iter = servic.GetVariableVectorMap().find(sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY);

			if(iter != servic.GetVariableVectorMap().end())
			{
				for(int i = 0; i<  iter->second.size();i++)
					right.push_back( iter->second.at(i).GetValue());
			}
			
			pCDigitalSignature->SetParas(right);
			
			if(!pCDigitalSignature->Verify(m_mInPara))
			{	
				throw(MyUtility::CMyException("Error Verify  :" + sRequestVerifier + "[" + m_mInPara.Join("&","=") + "]",iINPUT_VERIFY_INVALID));
				result =  false;
			}
			if(sigleton_flag != "singleton" )
			{
				delete pCDigitalSignature; pCDigitalSignature = NULL;
			}
		}
	}
	
	return result;
}

//##ModelId=4C11A67D00EE
void MyCGI::CCGIEntry::DoTranslate() throw(MyUtility::CMyException)
{
	DEBUG_LOGER << "\tDoTranslate"<< LOGER_ETAG ;//<< log4cpp::CategoryStream::ENDLINE;
///*	
	MyUtility::CStringVectorMap::iterator iter;


	for( iter = m_mInPara.begin();
		iter != m_mInPara.end();
		iter++)
	{
		//INFO_LOGER<< iter->first << " : " << iter->second.size() ;//<< log4cpp::CategoryStream::ENDLINE;

		std::string trsltor,method,func;

		try
		{
			trsltor = this->m_Config.GetElement(iter->first).GetTranslator();	
				MyUtility::CStringVector v;
				v.Split(trsltor,":");
				if(v.size() == 3)
				{
					trsltor = v[0];
					method = v[1];
					func = v[2];
				}
		}
		catch(MyUtility::CMyException & exp)
		{
			INFO_LOGER<< "Notice : " << exp.ToString() << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
			continue;
		}


		std::string sigleton_flag ("");

		try
		{
			sigleton_flag = m_Config.GetService("_convert_config").GetVarVal(trsltor);
		}
		catch(...){};

		

		CConvertor * pCConvertor = NULL;

		if(sigleton_flag == "singleton")
		{
			pCConvertor = g_CConvertorFactory.GetSingletonInstance(trsltor);
		}
		else
		{
			pCConvertor = g_CConvertorFactory.GetInstance(trsltor);
		}

		if(NULL == pCConvertor)
		{
			throw(MyUtility::CMyException("Error: Not Installed Convertor - " + trsltor,iPREPARE_CONFIG_ERROR));
			return ;
		}
		
		
		if(method ==sCHECKER_METHOD_SINGLE)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				DEBUG_LOGER << "Before convert :" << iter->second[i] << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

				pCConvertor->DoSingle(iter->second[i],func);

				DEBUG_LOGER << "After convert :" << iter->second[i] << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
		
			}
		}
		else if(method ==sCHECKER_METHOD_COMPLEX)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				pCConvertor->DoComplex(iter->second,m_mInPara,func);
			}
		}
		else
			;

		if(sigleton_flag != "singleton")
		{
			delete pCConvertor;
		}
		
		
		
	}

//*/
	
	
}

//##ModelId=4C11A75C01C6
bool MyCGI::CCGIEntry::CheckPopedom() throw(MyUtility::CMyException)
{
	bool result = false;
	
	DEBUG_LOGER << "\tCheckPopedom" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	return result;
}

//##ModelId=4C11A7D00303
bool MyCGI::CCGIEntry::CheckFrequence() throw(MyUtility::CMyException)
{
	bool result = false;
	
	DEBUG_LOGER << "\tCheckFrequence" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	return result;
}

//##ModelId=4C11A80801FB
int MyCGI::CCGIEntry::CommitTrans() throw(MyUtility::CMyException)
{
	DEBUG_LOGER << "\tCommitTrans" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	int ret = 0;

	const MyConfig::CService &servic = m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name));




	CTransaction * pTransaction = NULL;

	if(servic.GetVarVal(sSINGLETON_TRANSACTION_FLAG)	 == "true")
	{
		pTransaction = MyCGI::g_CTransactionFactory.GetSingletonInstance(m_mInPara.GetFirst(g_pszTransactionID_name));
	}
	else
	{
		pTransaction = MyCGI::g_CTransactionFactory.GetInstance(m_mInPara.GetFirst(g_pszTransactionID_name));
	}
	
	if(NULL == pTransaction)
	{
		throw(MyUtility::CMyException("没有安装好的处理逻辑:" + m_mInPara.GetFirst(g_pszTransactionID_name),iPREPARE_CONFIG_ERROR));
		ret = 99;
	}
	else
	{
		DEBUG_LOGER<< "Exec transaction : " << m_mInPara.GetFirst(g_pszTransactionID_name) << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
//		pTransaction->Do(m_mInPara,m_mOutPara);
		ret = pTransaction->Do(m_mInPara, m_mInEnv, m_mInCookie, m_mInFileData, m_mOutPara,m_Config);

		if(servic.GetVarVal(sSINGLETON_TRANSACTION_FLAG)	 != "true")
			delete pTransaction;
	}

	return ret;
}

//##ModelId=4C11AACC0334
bool MyCGI::CCGIEntry::ValidOutput() throw(MyUtility::CMyException)
{
	bool result = false;
	
	DEBUG_LOGER << "\tValidOutput" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	MyUtility::CStringVectorMap::const_iterator iter;


	for( iter = m_mOutPara.begin();
		iter != m_mOutPara.end();
		iter++)
	{
		INFO_LOGER<< iter->first << " : " << iter->second.size() << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		std::string fmt,chker,desc,method(sCHECKER_METHOD_SINGLE);

		try
		{
			fmt = this->m_Config.GetElement(iter->first).GetFormat();
			chker = this->m_Config.GetElement(iter->first).GetChecker();	
				MyUtility::CStringVector v;
				v.Split(chker,":");
				if(v.size() == 2)
				{
					chker = v[0];
					method = v[1];
				}
			desc = this->m_Config.GetElement(iter->first).GetDesc();
		}
		catch(MyUtility::CMyException & exp)
		{
			INFO_LOGER<< "Notice : " << exp.ToString()<< LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

			std::string sIolist_type = m_Config.GetService("_element_config").GetVarVal("io_list");

			if(sIolist_type == "loose" )
				continue;
			else			
				throw(MyUtility::CMyException("Error: Lack Element config : - " + iter->first,iEXECUTE_CONFIG_ERROR));
			
		}


		std::string sigleton_flag ("");

		try
		{
			sigleton_flag = m_Config.GetService("_check_config").GetVarVal(chker);
		}
		catch(...){};

		

		CChecker * pChecker = NULL;

		if(sigleton_flag == "singleton")
		{
			pChecker = MyCGI::g_CCheckerFactory.GetSingletonInstance(chker);
		}
		else
		{
			pChecker = MyCGI::g_CCheckerFactory.GetInstance(chker);
		}
		//CChecker * pChecker = MyCGI::g_CCheckerFactory.GetSingletonInstance(chker);

		if(NULL == pChecker)
		{
			throw(MyUtility::CMyException("Error: Not Installed Checker - " + chker,iEXECUTE_CONFIG_ERROR));
			return result;
		}
		
		
		if(method ==sCHECKER_METHOD_SINGLE)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				result = pChecker->DoSingle(iter->second[i],fmt);

				if(!result)  break;
				
			}
		}
		else if(method ==sCHECKER_METHOD_COMPLEX)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				result = pChecker->DoComplex(iter->second,m_mInPara,fmt);
			}
		}
		else
			;

		if(sigleton_flag != "singleton")
		{
			delete pChecker;pChecker = NULL;
		}
		
		if(!result)
		{		
			INFO_LOGER<<iter->first << " Error Format " << desc << LOGER_ETAG;
			throw(MyUtility::CMyException(desc,iOUTPUT_FORMAT_ERROR));
		}

		
	}

		
	
	

	return result;
}

//##ModelId=4C11AB27023F
bool MyCGI::CCGIEntry::TranslateOutput() throw(MyUtility::CMyException)
{
	bool result = false;
	
	DEBUG_LOGER << "\tTranslateOutput" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
	MyUtility::CStringVectorMap::iterator iter;


	for( iter = m_mOutPara.begin();
		iter != m_mOutPara.end();
		iter++)
	{
//		INFO_LOGER<< iter->first << " : " << iter->second.size() ;//<< log4cpp::CategoryStream::ENDLINE;

		std::string trsltor,method,func;

		try
		{
			trsltor = this->m_Config.GetElement(iter->first).GetTranslator();	
				MyUtility::CStringVector v;
				v.Split(trsltor,":");
				if(v.size() == 3)
				{
					trsltor = v[0];
					method = v[1];
					func = v[2];
				}
		}
		catch(MyUtility::CMyException & exp)
		{
			INFO_LOGER<< "Notice : " << exp.ToString() << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
			continue;
		}

		std::string sigleton_flag ("");

		try
		{
			sigleton_flag = m_Config.GetService("_convert_config").GetVarVal(trsltor);
		}
		catch(...){};

		

		CConvertor * pCConvertor = NULL;

		if(sigleton_flag == "singleton")
		{
			pCConvertor = g_CConvertorFactory.GetSingletonInstance(trsltor);
		}
		else
		{
			pCConvertor = g_CConvertorFactory.GetInstance(trsltor);
		}

		if(NULL == pCConvertor)
		{
			throw(MyUtility::CMyException("Error: Not Installed Convertor - " + trsltor ,iEXECUTE_CONFIG_ERROR));
			return false;
		}
		
		
		if(method ==sCHECKER_METHOD_SINGLE)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				DEBUG_LOGER << "Before convert :" << iter->second[i] << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

				pCConvertor->DoSingle(iter->second[i],func);

				DEBUG_LOGER << "After convert :" << iter->second[i] << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
		
			}
		}
		else if(method ==sCHECKER_METHOD_COMPLEX)
		{
			for(int i=0; i< iter->second.size();i++)
			{
				pCConvertor->DoComplex(iter->second,m_mInPara,func);
			}
		}
		else
			;

		if(sigleton_flag != "singleton")
		{
			delete pCConvertor;
		}
		
		
		
	}

	return result;
}

//##ModelId=4C11AB410202
bool MyCGI::CCGIEntry::SignOutput() throw(MyUtility::CMyException)
{
	bool result = false;
	
	DEBUG_LOGER << "\tSignOutput"<< LOGER_ETAG ;//<< log4cpp::CategoryStream::ENDLINE;

	const MyConfig::CService &servic = m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name));
	
	std::string sResponseSigner = servic.GetVarVal(sRESERVED_VAR_NAME_RESPONSE_SIGNER);


	std::string sigleton_flag;
	try
	{
		sigleton_flag = m_Config.GetService("_signature_config").GetVarVal(sResponseSigner);
	}
	catch(...){};
	CDigitalSignature * pCDigitalSignature =NULL;
	if(sigleton_flag == "singleton" )
	{
		pCDigitalSignature = g_CDigitalSignatureFactory.GetSingletonInstance(sResponseSigner);
	}
	else
	{
		pCDigitalSignature = g_CDigitalSignatureFactory.GetInstance(sResponseSigner);		
	}
	//CDigitalSignature * pCDigitalSignature = g_CDigitalSignatureFactory.GetInstance(sResponseSigner);

	if(NULL != pCDigitalSignature)
	{
		//MyUtility::CStringMap  right;
		//right["key"] = servic.GetVarVal(sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY);
		MyUtility::CStringVector  right;

			MyConfig::CVariableVectorMap::const_iterator iter = servic.GetVariableVectorMap().find(sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY);

			if(iter != servic.GetVariableVectorMap().end())
			{
				for(int i = 0; i<  iter->second.size();i++)
					right.push_back( iter->second.at(i).GetValue());
			}
			
		pCDigitalSignature->SetParas(right);
		
		if(!pCDigitalSignature->Sign(m_mOutPara))
		{	
			throw(MyUtility::CMyException("Error Sign  O:" + sResponseSigner  ,iOUTPUT_SIGN_ERROR));
			result =  false;
		}

		if(sigleton_flag != "singleton" )
		{
			delete pCDigitalSignature; pCDigitalSignature = NULL;
		}
	}

	
	
	return result;
}

//##ModelId=4C11AB600213
void MyCGI::CCGIEntry::SetOupt() throw(MyUtility::CMyException)
{	
	DEBUG_LOGER << "\tSetOupt" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	CMyDispatcher disp;

	std::string res ;

	std::string sDefault ;
		sDefault   = "<?xml version=\"1.0\" encoding=\"gbk\" ?>\r\n\r\n";
		sDefault += "<root>\r\n";
		sDefault += "<retcode>\r\n";
		sDefault += m_mOutPara.GetFirst("retcode");
		sDefault += "</retcode>\r\n";
		sDefault += "<retmsg>\r\n";
		sDefault += m_mOutPara.GetFirst("retmsg");
		sDefault += "</retmsg>\r\n";
		sDefault += "<debug>\r\n";
		sDefault += "无缺省的配置文件";
		sDefault += "</debug>\r\n";
		sDefault += "</root>\r\n";

	
	std::string ftempname ;//= m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name)).GetVarVal(sRESERVED_VAR_NAME_OUTPUT_TEMPLATE);

	// 根据错误码选取不同的模版进行输出
	std::string sErrorCode = m_mOutPara.GetFirst("retcode");
	std::string sStatic_Specific_ErrorTemplate =  "";
	std::string sGlobal_Specific_ErrorTemplate =  "";	
	std::string sStatic_Default_ErrorTemplate =  "";
	std::string sGlobal_Default_ErrorTemplate =  "";	

	/* plus 20101021
		由于tid=mybpml无法个性化
		 服务的唯一标志	
		 只有cgi的对外输出才指定私有模版
	*/


	std::string s_methodname = m_mInPara.GetFirst("method");
	string::size_type loc1 = s_methodname.find(".cgi",s_methodname.length() - 4,4);
	
	if( loc1 == string::npos )
	{
		if(m_Config.IsExistService(m_mInPara.GetFirst(g_pszTransactionID_name)))
		{				
			DEBUG_LOGER<< "Exist Service Configure " << m_mInPara.GetFirst(g_pszTransactionID_name)<< LOGER_ETAG;
			sStatic_Specific_ErrorTemplate = m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name)).GetVarVal(sSERVICE_TEMPLATE_PREFIX+sErrorCode);
			sStatic_Default_ErrorTemplate  =  m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name)).GetVarVal(sSERVICE_TEMPLATE_PREFIX+sTEMPLATE_DEFAULT);
		
			DEBUG_LOGER<< "Static Specific Output template	:" << sSERVICE_TEMPLATE_PREFIX+sErrorCode << " = "
				<< sStatic_Specific_ErrorTemplate<< LOGER_ETAG;
			DEBUG_LOGER<< "Static Default  Output template	" << sSERVICE_TEMPLATE_PREFIX+sTEMPLATE_DEFAULT << " = "
				<< sStatic_Default_ErrorTemplate<< LOGER_ETAG;		
		}
	}
	else
	{
		//指定空间
		std::string s_method = "mybpml::" + s_methodname; 
		if(m_Config.IsExistService(s_method))
		{
			sStatic_Specific_ErrorTemplate = m_Config.GetService(s_method).GetVarVal(sSERVICE_TEMPLATE_PREFIX+sErrorCode);
			sStatic_Default_ErrorTemplate = m_Config.GetService(s_method).GetVarVal(sSERVICE_TEMPLATE_PREFIX+sTEMPLATE_DEFAULT);
		}
		
		//为了少改运营上的配置文件，
		//兼容老的参数，如果此参数不设置，还是使用原配置
		//plus 20101104
		if(m_Config.IsExistService(m_mInPara.GetFirst(g_pszTransactionID_name)))
		{				
			DEBUG_LOGER<< "Exist_Service_Configure1104 " << m_mInPara.GetFirst(g_pszTransactionID_name)<< LOGER_ETAG;
			if (sStatic_Specific_ErrorTemplate.empty())
			{
				sStatic_Specific_ErrorTemplate = m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name)).GetVarVal(sSERVICE_TEMPLATE_PREFIX+sErrorCode);
			}

			if (sStatic_Default_ErrorTemplate.empty())
			{
				sStatic_Default_ErrorTemplate  =  m_Config.GetService(m_mInPara.GetFirst(g_pszTransactionID_name)).GetVarVal(sSERVICE_TEMPLATE_PREFIX+sTEMPLATE_DEFAULT);
			}
		}

		DEBUG_LOGER<< "Static Specific Output template  :" << sSERVICE_TEMPLATE_PREFIX+sErrorCode 
			<< " = "<< sStatic_Specific_ErrorTemplate<< LOGER_ETAG;
		DEBUG_LOGER<< "Static Default  Output template  " << sSERVICE_TEMPLATE_PREFIX+sTEMPLATE_DEFAULT 
			<< " = "<< sStatic_Default_ErrorTemplate<< LOGER_ETAG;
	}
	
	if(m_Config.IsExistService(sERROR_TEMPLATE_CONFIG))
	{
		DEBUG_LOGER<< "Exist Service Configure " << sERROR_TEMPLATE_CONFIG<< LOGER_ETAG;
		sGlobal_Specific_ErrorTemplate =  m_Config.GetService(sERROR_TEMPLATE_CONFIG).GetVarVal(sErrorCode);
		sGlobal_Default_ErrorTemplate =  m_Config.GetService(sERROR_TEMPLATE_CONFIG).GetVarVal(sTEMPLATE_DEFAULT);
		
		DEBUG_LOGER<< "Global Specific Output template  " << sErrorCode << " = " << sGlobal_Specific_ErrorTemplate<< LOGER_ETAG;
		DEBUG_LOGER<< "Global Default  Output template  " << sTEMPLATE_DEFAULT << " = " << sGlobal_Default_ErrorTemplate<< LOGER_ETAG;	
	}

	if(sStatic_Specific_ErrorTemplate != "" )
	{
		ftempname = sStatic_Specific_ErrorTemplate;
		DEBUG_LOGER<< "Output Template SS:  " << ftempname<< LOGER_ETAG;
	}
	else if(sGlobal_Specific_ErrorTemplate != "" )
	{
		ftempname = sGlobal_Specific_ErrorTemplate;
		DEBUG_LOGER<< "Output Template GS:  " << ftempname<< LOGER_ETAG;
	}
	else if(sStatic_Default_ErrorTemplate != "" )
	{
		ftempname = sStatic_Default_ErrorTemplate;
		DEBUG_LOGER<< "Output Template SD:  " << ftempname<< LOGER_ETAG;
	}
	else if(sGlobal_Default_ErrorTemplate != "" )
	{
		ftempname = sGlobal_Default_ErrorTemplate;
		DEBUG_LOGER<< "Output Template :  GD" << ftempname<< LOGER_ETAG;
	}
	else		
	{
		ERROR_LOGER << "Config error ,no defaut config file . service name = "<< m_mInPara.GetFirst(g_pszTransactionID_name) << 
			" errcd = " << sErrorCode<< LOGER_ETAG;

		*m_pCCgiIO << sDefault;
		
		return ;
		
	}
	
	disp.StartWork(ftempname,res,m_mOutPara);
	
	//DEBUG_LOGER << "The last output data :[ " << res << "]"<< LOGER_ETAG ;

	*m_pCCgiIO << res;
}
void MyCGI::CCGIEntry::ErrorDump(MyUtility::CMyException & exp)
{
	DEBUG_LOGER << "\t ErrorDump" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

}

 
void MyCGI::CCGIEntry::InitLoger()
{
	std::string initFileName;
	try 
	{
		initFileName = m_Config.GetService("_log4cpp_config").GetVarVal("property_config_path");;

		LOG_INIT(initFileName,"CGI","*");
				
	} 
	catch(...)
	{
	
		throw(MyUtility::CMyException("Err: Configure file [" + sCONFIGFILE_PATH + "]  for log4cpp" ,iPREPARE_CONFIG_ERROR));
		return ;
	}


}

void MyCGI::CCGIEntry::ClearLoger()
{
	LOG_EXIT();
}



// CGI 输入参数
MyCGI::CCGIEntry * g_CCGIEntry = NULL;

 
int main(int argc,char ** argv)
{	
	try
	{
		MyUtility::CMySmartPoint <MyCGI::CCGIEntry> cgiEntry(g_CCGIEntry);
		
		cgiEntry->Start(argc,argv);	
	}
	catch(MyUtility::CMyException & exp)
	{
		std::cout << exp.ToString() << std::endl;
		
	}
	catch(...)
	{
		std::cout  << MyCGI::sERROR_SYSTEM_INIT << std::endl;
	}
	return 0;
}
