// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CFastCgiIO.h"

//##ModelId=4C11D56E02FD
size_t MyCGI::CFastCgiIO::read(char *data, size_t length)
{
	return FCGX_GetStr(data, length, fRequest.in);
}

//##ModelId=4C11D5730148
std::string MyCGI::CFastCgiIO::getenv(const char *inName)
{
	return m_mEnv[inName];
}

//##ModelId=4C11D5890167
std::ostream &MyCGI::CFastCgiIO::err()
{
	return fErr;
}

//##ModelId=4C11D5CF0138
MyCGI::CFastCgiIO::CFastCgiIO(const CFastCgiIO &io)
	: CCgiIO(io,fOutBuf,io.m_mEnv),
		fRequest(io.fRequest), 
		fErr(&fErrBuf)
{
	rdbuf(&fOutBuf);
	fErr.rdbuf(&fErrBuf);
}


//##ModelId=4C11D5CF0157
MyCGI::CFastCgiIO::~CFastCgiIO()
{
}

//##ModelId=4C11D601002E
MyCGI::CFastCgiIO::CFastCgiIO(FCGX_Request &request)
	: 	CCgiIO(fOutBuf),
		fRequest(request), 
		fOutBuf(request.out), 
		fErrBuf(request.err), 
		fErr(&fErrBuf)
{
	rdbuf(&fOutBuf);
	fErr.rdbuf(&fErrBuf);

	// Parse environment
	for(char **e = fRequest.envp; *e != NULL; ++e) 
	{
		std::string s(*e);
		std::string::size_type i = s.find('=');
		
		if(i == std::string::npos)
		{
			//throw std::runtime_error("Illegally formed environment");
			continue;
		}
			
		m_mEnv[s.substr(0, i)] = s.substr(i + 1);
	}
}


