// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************
#ifndef md5_xor_D99_T99_CDATABASEHASH_H_HEADER_INCLUDED_B3CA14F7
#define md5_xor_D99_T99_CDATABASEHASH_H_HEADER_INCLUDED_B3CA14F7

#include "mysoft_app.h"

#include "CDatabaseHash.h"
#include "CDatabaseHashFactory.h"


#include <openssl/evp.h>
#include <openssl/sha.h>
#include "openssl/md5.h"

namespace MyAPP {
// 数据库hash算法接口，用于分布式资料库的离散存放与定位。
// 
// 关注三个纬度：node，database，table
//##ModelId=4C358A1503E0
class md5_xor_D99_T99_CDatabaseHash:public CDatabaseHash
{
  public:
    // 初始化，使用一个字符串数组
    //##ModelId=4C3595FD02D5
    virtual void Init(const std::string &inPara);

    //##ModelId=4C3598580183
    md5_xor_D99_T99_CDatabaseHash();

    //##ModelId=4C35985801E1
    virtual ~md5_xor_D99_T99_CDatabaseHash();
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
}//MyAPP


#endif /*md5_xor_D99_T99_ CDATABASEHASH_H_HEADER_INCLUDED_B3CA14F7 */
