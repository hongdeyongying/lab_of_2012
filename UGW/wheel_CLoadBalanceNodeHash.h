// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************
#ifndef wheel_CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7
#define wheel_CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7


#include "CLoadBalanceNodeHash.h"
#include "CLoadBalanceNodeHashFactory.h"


#include <openssl/evp.h>
#include <openssl/sha.h>
#include "openssl/md5.h"

namespace MyTENPAYAPI {
// ���ݿ�hash�㷨�ӿڣ����ڷֲ�ʽ���Ͽ����ɢ����붨λ��
// 
// ��ע����γ�ȣ�node��database��table
//##ModelId=4C358A1503E0
class wheel_CLoadBalanceNodeHash:public CLoadBalanceNodeHash
{
  public:
    // ��ʼ����ʹ��һ���ַ�������
    //##ModelId=4C3595FD02D5
    virtual void Init(const std::string &inPara);

    //##ModelId=4C3598580183
    wheel_CLoadBalanceNodeHash();

    //##ModelId=4C35985801E1
    virtual ~wheel_CLoadBalanceNodeHash();
/*
    //##ModelId=4C3598580200
    virtual const& GetDatabasePostfix() const;

    //##ModelId=4C35986E0126
    virtual const& GetDatabasePostfix(const std::string &inPara) const;

    //##ModelId=4C359858024F
    virtual const& GetNodePostfix() const;

    //##ModelId=4C359858027D
    virtual const& GetNodePostfix(const std::string &inPara) const;

    //##ModelId=4C35985802AC
    virtual const& GetTablePostfix() const;

    //##ModelId=4C35985802DB
    virtual const& GetTablePostfix(const std::string &inPara) const;
//*/private:
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
}//MyTENPAYAPI


#endif /*wheel_ CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7 */
