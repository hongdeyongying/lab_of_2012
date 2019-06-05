// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CChecker.h"

//##ModelId=4C11D76801E4
bool MyCGI::CChecker::DoSingle(const std::string &inVal,const std::string &inFmt)
{
	return true;
}

//##ModelId=4C11D8E1019E
bool MyCGI::CChecker::DoSingle(const MyUtility::CStringVector &inVal,const std::string &inFmt)
{
	return true;
}

//##ModelId=4C11D9110304
bool MyCGI::CChecker::DoComplex(const std::string &inVal, const MyUtility::CStringMap &inOthers,const std::string &inFmt)
{
	return true;
}

//##ModelId=4C11D9110371
bool MyCGI::CChecker::DoComplex(const MyUtility::CStringVector &inVal, const MyUtility::CStringVectorMap &inOthers,const std::string &inFmt)
{
	return true;
}

