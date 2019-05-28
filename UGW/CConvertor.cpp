// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CConvertor.h"

//##ModelId=4C11DB8401FF
bool MyCGI::CConvertor::DoComplex(std::string &ioVal, const MyUtility::CStringMap &inOthers, const std::string &inMethod)
{
	return false;
}

//##ModelId=4C11DB84023E
bool MyCGI::CConvertor::DoComplex(MyUtility::CStringVector &inVal, MyUtility::CStringVectorMap &inOthers, const std::string &inMethod)
{
	return false;
}

//##ModelId=4C11DB84027C
bool MyCGI::CConvertor::DoSingle(std::string &inVal, const std::string &inMethod)
{
	return false;
}

//##ModelId=4C11DB84029C
bool MyCGI::CConvertor::DoSingle(MyUtility::CStringVector &inVal, const std::string &inMethod)
{
	return false;
}

