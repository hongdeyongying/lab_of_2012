// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
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

