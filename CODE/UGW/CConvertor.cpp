// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
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

