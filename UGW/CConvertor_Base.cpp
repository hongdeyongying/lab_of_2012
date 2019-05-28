// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CConvertor_Base.h"

#include "CBaseEncode.h"

#include "CConvertorFactory.h"

const std::string sURLENCODE("urlencode");
const std::string sURLDECODE("urldecode");
const std::string sXMLENCODE("xmlencode");
const std::string sXMLDECODE("xmldecode");



//##ModelId=4C11DD69025B
bool MyCGI::CConvertor_Base::DoComplex(std::string &ioVal, const MyUtility::CStringMap &inOthers, const std::string &inMethod)
{
	return false;
}

//##ModelId=4C11DD69028A
bool MyCGI::CConvertor_Base::DoComplex(MyUtility::CStringVector &inVal, MyUtility::CStringVectorMap &inOthers, const std::string &inMethod)
{
	return false;
}

//##ModelId=4C11DD6902C8
bool MyCGI::CConvertor_Base::DoSingle(std::string &inVal, const std::string &inMethod)
{
	bool result = true;
	
	if( inMethod == sURLENCODE )
	{
		MyUtility::CBaseEncode::UrlEncode(inVal);
	}
	else if(inMethod == sURLDECODE )
	{
		MyUtility::CBaseEncode::UrlDecode(inVal);
	}
	else if(inMethod == sXMLENCODE )
	{
		MyUtility::CBaseEncode::XmlEncode(inVal);
	}
	else if(inMethod == sXMLDECODE )
	{
		MyUtility::CBaseEncode::XmlDecode(inVal);
	}
	else
	{
		result = false;
	}
	
	return result;
}

//##ModelId=4C11DD6902D8
bool MyCGI::CConvertor_Base::DoSingle(MyUtility::CStringVector &inVal, const std::string &inMethod)
{
	bool result = true;
	
	MyUtility::CStringVector::iterator iter;
	
	for(iter = inVal.begin(); iter != inVal.end(); iter++ )
	{
		result = DoSingle(*iter,inMethod);
		
		if(!result) break;
	}
	
	return result;
}

MyCGI::CConvertorFactory<MyCGI::CConvertor_Base> for_CConvertorFactory_method("base");




