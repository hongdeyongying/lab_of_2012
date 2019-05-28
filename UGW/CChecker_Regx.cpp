// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CChecker_Regx.h"

#include "boost/regex.hpp"

//##ModelId=4C11DBD10398
bool MyCGI::CChecker_Regx::DoSingle(const std::string &inVal,const std::string &inFmt)
{
	const boost::regex e(inFmt);
    
	return boost::regex_match(inVal.c_str(), e);
}

//##ModelId=4C11DBD103D6
bool MyCGI::CChecker_Regx::DoSingle(const MyUtility::CStringVector &inVal,const std::string &inFmt)
{
	MyUtility::CStringVector::const_iterator iter;
	
	bool res = true;
	
	const boost::regex e(inFmt);
	
	for(iter = inVal.begin(); iter != inVal.end(); iter++ )
	{
		res = boost::regex_match(iter->c_str(), e);
		
		if(!res) break;
	}
	
	return res;
}

//##ModelId=4C11DBD2001D
bool MyCGI::CChecker_Regx::DoComplex(const std::string &inVal, const MyUtility::CStringMap &inOthers,const std::string &inFmt)
{
	return false;
}

//##ModelId=4C11DBD2003D
bool MyCGI::CChecker_Regx::DoComplex(const MyUtility::CStringVector &inVal, const MyUtility::CStringVectorMap &inOthers,const std::string &inFmt)
{
	return false;
}


MyCGI::CCheckerFactory<MyCGI::CChecker_Regx> for_CCheckerFactory_method("regex");



