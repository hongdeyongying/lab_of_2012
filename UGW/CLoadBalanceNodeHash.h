// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************
#ifndef CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7
#define CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7

#include <string> 

namespace MyTENPAYAPI {
// ���ݿ�hash�㷨�ӿڣ����ڷֲ�ʽ���Ͽ����ɢ����붨λ��
// 
// ��ע����γ�ȣ�node��database��table
//##ModelId=4C358A1503E0
class CLoadBalanceNodeHash
{
  public:
    // ��ʼ����ʹ��һ���ַ���
    //##ModelId=4C3595FD02D5
    virtual void Init(const std::string &inPara);

    //##ModelId=4C3598580183
    CLoadBalanceNodeHash();

    //##ModelId=4C35985801E1
    virtual ~CLoadBalanceNodeHash();

    //##ModelId=4C359858024F
    virtual const std::string & GetNodePostfix() const;

    //##ModelId=4C359858027D
    virtual const std::string & GetNodePostfix(const std::string &inPara) ;

  protected:
    //##ModelId=4C35981600A6
    std::string m_sNodePostfix;
};
}// namespace MyTENPAYAPI


#endif /* CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7 */
