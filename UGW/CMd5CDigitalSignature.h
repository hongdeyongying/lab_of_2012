#include "CDigitalSignature.h"
// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CMD5CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D50F9D
#define CMD5CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D50F9D

#include "CDigitalSignatureFactory.h"

#include <openssl/evp.h>
#include <openssl/sha.h>
#include "openssl/md5.h"

namespace MyCGI {

//##ModelId=4BF65FEB00B8
class CMd5CDigitalSignature : public CDigitalSignature
{
  public:
    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE7980233
    virtual bool Verify(const MyUtility::CStringVectorMap &inParas);

    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE7980252
    virtual bool Verify(const std::string &inSrc, const std::string &inRes);

    // 签名成功返回true，否则返回false
    // m_mParas["key"] 
    //##ModelId=4C2AE7980262
    virtual bool Sign(MyUtility::CStringVectorMap &ioParas);

    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE7980281
    virtual bool Sign(const std::string &inSrc, std::string &outRes);
  private:
  	std::string &md5(const std::string &in, std::string &out)
	{
		char szSign[1024] = {0};

		unsigned char md[MD5_DIGEST_LENGTH];

		char *pszResult = szSign;

		EVP_Digest((void *)in.data(),in.size(),md,NULL,EVP_md5(), NULL);

		for (int i=0; i<MD5_DIGEST_LENGTH; i++)
			sprintf(pszResult+2*i,"%02X",md[i]);

		out =  szSign;

		return out;
	}

};

} // namespace MyCGI



#endif /* CMD5CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D50F9D */
