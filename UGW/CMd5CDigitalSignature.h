#include "CDigitalSignature.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
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
    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE7980233
    virtual bool Verify(const MyUtility::CStringVectorMap &inParas);

    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE7980252
    virtual bool Verify(const std::string &inSrc, const std::string &inRes);

    // ǩ���ɹ�����true�����򷵻�false
    // m_mParas["key"] 
    //##ModelId=4C2AE7980262
    virtual bool Sign(MyUtility::CStringVectorMap &ioParas);

    // �����֤�ɹ�����true�����򷵻�false
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
