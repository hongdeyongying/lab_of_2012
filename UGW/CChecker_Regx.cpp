// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
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



