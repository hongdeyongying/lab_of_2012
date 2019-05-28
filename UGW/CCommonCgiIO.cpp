// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CCommonCgiIO.h"

//##ModelId=4C11D65403C8
std::string MyCGI::CCommonCgiIO::getenv(const char *inName)
{
	return m_mEnv[inName];
}

//##ModelId=4C11D68802BF
std::string MyCGI::CCommonCgiIO::getenv(const string &inName)
{
	return m_mEnv[inName];
}

//##ModelId=4C11D71F034B
MyCGI::CCommonCgiIO::CCommonCgiIO()
{
	LOGER_DEBUG << LOGER_ETAG;

	for(char **e = environ; *e != NULL; ++e) 
	{
		std::string s(*e);
		std::string::size_type i = s.find('=');
		
		if(i == std::string::npos)
		{
			//throw std::runtime_error("Illegally formed environment");
			continue;
		}
			
		m_mEnv[s.substr(0, i)] = s.substr(i + 1);

		LOGER_INFO <<  "m_mEnv." << s.substr(0, i) << "  = " <<   s.substr(i + 1) << LOGER_ETAG;
	}

}


//##ModelId=4C11D71F035B
MyCGI::CCommonCgiIO::~CCommonCgiIO()
{
}

