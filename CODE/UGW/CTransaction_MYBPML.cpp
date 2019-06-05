// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CTransaction_MYBPML.h"

#include "CTransactionFactory.h"


#include "CMyDispatcher.h"

static const string sServiceName("mybpml");
static const string sMethodName("method");

static const string sServiceNameSpace("mybpml::");


MyAPP::CTransaction_MYBPML::CTransaction_MYBPML()
{
}
MyAPP::CTransaction_MYBPML::~CTransaction_MYBPML()
{
}
//##ModelId=4C11DABC033C
int  MyAPP::CTransaction_MYBPML::Do(
        // 输入参数
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // 输出参数
        MyUtility::CStringVectorMap& outPara,
        //配置文件
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException)
{
	int result = 0;


	std::string method = sServiceNameSpace + inPara.GetFirst(sMethodName); 

	if(!config.IsExistService(method))
	{
		outPara["retcode"].push_back("10001001");
		outPara["retmsg"].push_back("配置文件错误，不存在相应方法的配置属性");		

		return result;
	}
	std::string script = config.GetService(method).GetVarVal("script");
	
	std::string prefix_env = config.GetService(method).GetVarVal("prefix_env");
	std::string prefix_cookie = config.GetService(method).GetVarVal("prefix_cookie");
	std::string prefix_parameter = config.GetService(method).GetVarVal("prefix_parameter");
	std::string prefix_file_data = config.GetService(method).GetVarVal("prefix_file_data");

	DEBUG_LOGER<< "method = " << method << "\r\n" <<
		"script = " << script << "\r\n" <<
		"prefix_env = " << prefix_env << "\r\n" <<
		"prefix_cookie = " << prefix_cookie << "\r\n" <<
		"prefix_parameter = " << prefix_parameter << 
		"prefix_file_data = " << prefix_file_data  << LOGER_ETAG;
	//组织输入参数
	MyUtility::CStringVectorMap inData;
	//  环境变量
	MyUtility::CStringMap::const_iterator iterEnv = inEnv.begin();
	for(iterEnv;iterEnv != inEnv.end();iterEnv ++)
	{
		inData[prefix_env + iterEnv->first].push_back(iterEnv->second);
	}
	//  cookie
	MyUtility::CStringMap::const_iterator iterCookie = inCookie.begin();
	for(iterCookie;iterCookie != inCookie.end();iterCookie++)
	{
		inData[prefix_cookie + iterCookie->first].push_back(iterCookie->second);
	}
	// 输入参数
	MyUtility::CStringVectorMap::const_iterator iterPara = inPara.begin();
	for(iterPara;iterPara != inPara.end();iterPara++)
	{
		inData[prefix_parameter + iterPara->first].insert(inData[prefix_parameter + iterPara->first].end(),iterPara->second.begin(),iterPara->second.end());
	}
	// 输入的文件
	MyUtility::CStringVectorMap::const_iterator iterFile = inFileData.begin();
	for(iterFile;iterFile != inFileData.end();iterFile++)
	{
		inData[prefix_file_data + iterFile->first].insert(inData[prefix_file_data + iterFile->first].end(),iterFile->second.begin(),iterPara->second.end());
	}
	// 默认参数：配置文件中配置
	const MyConfig::CParameterVectorMap &mvPara = config.GetService(method).GetParameterVectorMap();

	MyConfig::CParameterVectorMap::const_iterator iterConfPara = mvPara.begin();
	for(iterConfPara;iterConfPara != mvPara.end();iterConfPara++)
	{
		if(inData.find(iterConfPara->first) == inData.end())
		{
			MyConfig::CParameterVector::const_iterator iterv = iterConfPara->second.begin();
			for(iterv;iterv !=  iterConfPara->second.end(); iterv++)
			{
				if((iterv->GetInExistMode() == "M") && (iterv->GetDefault() != "null"))
					inData[iterConfPara->first].push_back(iterv->GetDefault());
			}
		}
	}

	//执行脚本
	CMyDispatcher disp;

	std::string res ;
	int retcode = disp.StartWork(script,res,inData);
	
	DEBUG_LOGER << "BPML脚本的最后输出为: "<< retcode << " [ " << res << "]"<< LOGER_ETAG ;

	if(0 == retcode )
	{
		outPara["result"].push_back(res);
		outPara["retcode"].push_back("0");
		outPara["retmsg"].push_back("OK");
	}
	else
	{
		outPara["retcode"].push_back("20001001");
		outPara["retmsg"].push_back("BPML脚本执行错误");		
	}
	
	return result;
}


MyCGI::CTransactionFactory<MyAPP::CTransaction_MYBPML> for_mybpmlCTransactionFactory_method("mybpml");

