// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CRsaCDigitalSignature.h"


#include <openssl/evp.h>
#include <openssl/sha.h>
#include "openssl/md5.h"

//##ModelId=4C2AE79D02FE
bool MyCGI::CRsaCDigitalSignature::Verify(const MyUtility::CStringVectorMap &inParas)
{
}

//##ModelId=4C2AE79D031D
bool MyCGI::CRsaCDigitalSignature::Verify(const std::string &inSrc, const std::string &inRes)
{
}

//##ModelId=4C2AE79D033D
bool MyCGI::CRsaCDigitalSignature::Sign(MyUtility::CStringVectorMap &ioParas)
{
}

//##ModelId=4C2AE79D034C
bool MyCGI::CRsaCDigitalSignature::Sign(const std::string &inSrc, std::string &outRes)
{
}

MyCGI::CDigitalSignatureFactory<MyCGI::CRsaCDigitalSignature> for_CRsaDigitalSignatureFactory_method("rsa");

