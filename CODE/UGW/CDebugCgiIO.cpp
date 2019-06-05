// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CDebugCgiIO.h"

#include "CConfigEntry.h"
#include "CBaseEncode.h"

//##ModelId=4C11D6B20196
size_t MyCGI::CDebugCgiIO::read(char *outDat, size_t inLen)
{
	size_t hasRead = 0;
	
	while((m_sInIter != m_sIn.end()) && (hasRead < inLen ))
	{
		outDat[hasRead++] = *m_sInIter++;
	}
	
	return hasRead;
}

//##ModelId=4C11D6B20199
std::string MyCGI::CDebugCgiIO::getenv(const char *inName)
{
	return m_mEnv[inName];
}

//##ModelId=4C11D6B80177
std::string MyCGI::CDebugCgiIO::getenv(const std::string &inName)
{
	return m_mEnv[inName];
}

//##ModelId=4C11D725003E
MyCGI::CDebugCgiIO::CDebugCgiIO(const std::string &inFile,const std::string &inRequest)
{
	LOGER_DEBUG <<  inFile << "," << inRequest << ")" << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	MyConfig::CConfigEntry cfg;
	
	cfg.LoadService(inFile);
	
	const MyConfig::CVariableVectorMap & env = cfg.GetService(inRequest).GetVariableVectorMap();
	
	MyConfig::CVariableVectorMap::const_iterator iter;
	
	iter =  env.begin();
	
	for(;iter != env.end();iter++)
	{
		int size = iter->second.size();
		if( size != 0)
		{
			m_mEnv[iter->first] = iter->second.at(size-1).GetValue();
			LOGER_INFO <<  "m_mEnv." << iter->first << "  = " <<   iter->second.at(size-1).GetValue() << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;
		}
		
	}
	
	//根据REQUEST_METHOD  准备相关输入缓冲
	const std::string sHTTP_GET = "HTTP_GET";
	const std::string sHTTP_POST = "HTTP_POST";
	const std::string sHTTP_POST_MULTIPART = "HTTP_POST_MULTIPART";
	
	const MyConfig::CParameterVectorMap & para = cfg.GetService(inRequest).GetParameterVectorMap();
	
	
	if(cfg.GetService(inRequest).GetType() == sHTTP_GET)
	{
		//设置环境变量 QUERY_STRING
		std::string tmp;
		MyConfig::CParameterVectorMap::const_iterator iter;
		
		iter =  para.begin();
		
		for(;iter != para.end();iter++)
		{
			for(int i=0; i < iter->second.size(); i++)
			{
				tmp += iter->first;
				tmp += "=";
				tmp += iter->second.at(i).GetDefault();
				tmp += "&";
			}
		}
		m_mEnv["QUERY_STRING"] = tmp;
		LOGER_INFO <<  "QUERY_STRING : " << tmp << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		
	}
	else if(cfg.GetService(inRequest).GetType() == sHTTP_POST)
	{
		//设置输入参数 m_sIN
		MyConfig::CParameterVectorMap::const_iterator iter;

		//设置环境变量 		
		m_mEnv["REQUEST_METHOD"] = "post" ;
		
		iter =  para.begin();
		
		for(;iter != para.end();iter++)
		{
			for(int i=0; i < iter->second.size(); i++)
			{
				m_sIn += iter->first;
				m_sIn += "=";
				m_sIn += iter->second.at(i).GetDefault();
				m_sIn += "&";
			}
		}
		LOGER_INFO <<  "POST : \r\n" << m_sIn << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

		
	}
	else if(cfg.GetService(inRequest).GetType() == sHTTP_POST_MULTIPART)
	{
		//生成特定格式的输入
		string sBound = "-----------------------------AB" + MyUtility::CBaseEncode::IntToString(rand()*10000) + "CD";
		
		string sBoundBegin = "--" + sBound;
		string sBoundEnd = sBoundBegin + "--\r\n" ;
		
		//设置环境变量 		
		m_mEnv["CONTENT_TYPE"] = "multipart/form-data; boundary=" + sBound ;
		m_mEnv["REQUEST_METHOD"] = "post" ;
		
		//
		MyConfig::CParameterVectorMap::const_iterator iter;
		
		iter =  para.begin();
		
		for(;iter != para.end();iter++)
		{
			const std::string sHTTP_FORMDATA_FILE="file";
			
			for(int i=0; i < iter->second.size(); i++)
			{
				if(iter->second.at(i).GetDesc() == sHTTP_FORMDATA_FILE)
				{
					m_sIn += sBoundBegin;
					m_sIn += "\r\n";
					m_sIn += "Content-Disposition: form-data; name=\"" + iter->second.at(i).GetName() ;
					m_sIn += "\"; filename=\"" + iter->second.at(i).GetDefault() + "\"\r\nContent-Type: application/octet-stream \r\n\r\n";
					//读取文件内容放置其中
					ReadFile(iter->second.at(i).GetDefault());
					m_sIn += "\r\n";
				}
				else
				{
					m_sIn += sBoundBegin;
					m_sIn += "\r\n";
					m_sIn += "Content-Disposition: form-data; name=\"" + iter->second.at(i).GetName() + "\"\r\n\r\n";
					m_sIn += iter->second.at(i).GetDefault();
					m_sIn += "\r\n";
				}
			}

			
			
		}
		
		m_sIn += sBoundEnd;
		LOGER_INFO <<  "POST_MULTIPART : \r\n" << m_sIn << LOGER_ETAG;//<< log4cpp::CategoryStream::ENDLINE;

	}
	
	//设置长度 CONTENT_LENGTH
		m_mEnv["CONTENT_LENGTH"] = MyUtility::CBaseEncode::IntToString(m_sIn.size());
	//初始化输入缓冲区指针
		m_sInIter = m_sIn.begin();
}


//##ModelId=4C11D725006D
MyCGI::CDebugCgiIO::~CDebugCgiIO()
{
}

