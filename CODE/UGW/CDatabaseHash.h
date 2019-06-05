// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************
#ifndef CDATABASEHASH_H_HEADER_INCLUDED_B3CA14F7
#define CDATABASEHASH_H_HEADER_INCLUDED_B3CA14F7

#include "mysoft_app.h"

namespace MyAPP {
// ���ݿ�hash�㷨�ӿڣ����ڷֲ�ʽ���Ͽ����ɢ����붨λ��
// 
// ��ע����γ�ȣ�node��database��table
//##ModelId=4C358A1503E0
class CDatabaseHash
{
  public:
    // ��ʼ����ʹ��һ���ַ�������
    //##ModelId=4C3595FD02D5
    virtual void Init(const std::string &inPara);

    //##ModelId=4C3598580183
    CDatabaseHash();

    //##ModelId=4C35985801E1
    virtual ~CDatabaseHash();

    //##ModelId=4C3598580200
    virtual const std::string &GetDatabasePostfix() const;

    //##ModelId=4C35986E0126
    virtual const std::string & GetDatabasePostfix(const std::string &inPara) ;

    //##ModelId=4C359858024F
    virtual const std::string & GetNodePostfix() const;

    //##ModelId=4C359858027D
    virtual const std::string & GetNodePostfix(const std::string &inPara) ;

    //##ModelId=4C35985802AC
    virtual const std::string & GetTablePostfix() const;

    //##ModelId=4C35985802DB
    virtual const std::string & GetTablePostfix(const std::string &inPara) ;

  protected:
    //##ModelId=4C3597FE0057
    std::string m_sDatabasePostfix;

    //##ModelId=4C35981600A6
    std::string m_sNodePostfix;

    //##ModelId=4C35981601BF
    std::string m_sTablePostfix;

};
}// namespace MyAPP


#endif /* CDATABASEHASH_H_HEADER_INCLUDED_B3CA14F7 */
