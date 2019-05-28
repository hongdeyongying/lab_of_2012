// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CCgiIO.h"

//##ModelId=4C0C72E302A1
size_t MyCGI::CCgiIO::read(char *outDat, size_t inLen)
{
	return cgicc::CgiInput::read(outDat,inLen);
}

//##ModelId=4C0C739002E6
std::string MyCGI::CCgiIO::getenv(const char *inName)
{
	return cgicc::CgiInput::getenv(inName);
}

//##ModelId=4C0C73C302D8
MyCGI::CCgiIO::CCgiIO():
	std::ostream(std::cout.rdbuf())
{
}

//##ModelId=4C0C73EB0366
MyCGI::CCgiIO::~CCgiIO()
{
}

//##ModelId=4C0C73EB03A5
int MyCGI::CCgiIO::operator==(const CCgiIO& right)
{
	return true;
}

//##ModelId=4C0C73EC0049
int MyCGI::CCgiIO::operator!=(const CCgiIO& right)
{
	return ! operator==(right);
}

//##ModelId=4C0C7BDF0089
MyCGI::CCgiIO& MyCGI::CCgiIO::operator=(const CCgiIO& right)
{
	return *this;
}

//##ModelId=4C0C7C2200E9
MyCGI::CCgiIO::CCgiIO(const CCgiIO &input):
	std::ostream(std::cout.rdbuf())
{
	operator = (input);
}
MyCGI::CCgiIO::CCgiIO(const CCgiIO &input,std::streambuf & buf,const MyUtility::CStringMap & env):
	std::ostream(&buf),
	m_mEnv(env)
{
	operator = (input);

	
}
MyCGI::CCgiIO::CCgiIO(const CCgiIO &input,std::streambuf & buf):
	std::ostream(&buf)
{
	operator = (input);

	
}
MyCGI::CCgiIO::CCgiIO(std::streambuf & buf):
	std::ostream(&buf)
{
	
}

