// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CMd5CDigitalSignature.h"

//##ModelId=4C2AE7980233
bool MyCGI::CMd5CDigitalSignature::Verify(const MyUtility::CStringVectorMap &inParas)
{
	std::string inSrc,res,inRes;
	bool result= false;

	MyUtility::CStringVectorMap svm = inParas;

	MyUtility::CStringVectorMap::iterator iter = svm.find("sign");

	if(iter != svm.end())
	{
		MyUtility::CStringVector sv ;
		inRes = iter->second.at(0);

		sv.push_back(inRes);

		svm.erase(iter);

		inSrc = svm.Join("&","=");
		
		if(Sign(inSrc, res))
		{
			if(res == inRes)
				result = true;
		}

		svm["sign"] = sv;
	}
	return result;
}

//##ModelId=4C2AE7980252
bool MyCGI::CMd5CDigitalSignature::Verify(const std::string &inSrc, const std::string &inRes)
{
	std::string res;
	bool result= false;

	if(Sign(inSrc, res))
	{
		if(res == inRes)
			result = true;
	}

	return result;
}

//##ModelId=4C2AE7980262
bool MyCGI::CMd5CDigitalSignature::Sign(MyUtility::CStringVectorMap &ioParas)
{
	std::string src(ioParas.Join("&","=")),outRes;
	
	if(m_vParas.size() >= 1)
	{
		src += "&key="+m_vParas.at(0) ;
	}

	md5(src,outRes);

	ioParas["sign"].push_back( outRes);

	return true;
}

//##ModelId=4C2AE7980281
bool MyCGI::CMd5CDigitalSignature::Sign(const std::string &inSrc, std::string &outRes)
{
	std::string src(inSrc);
	
	if(m_vParas.size() >= 1)
	{
		src += "&key="+m_vParas.at(0) ;
	}

	md5(src,outRes);

	return true;
}


MyCGI::CDigitalSignatureFactory<MyCGI::CMd5CDigitalSignature> for_md5CDigitalSignatureFactory_method("md5");

