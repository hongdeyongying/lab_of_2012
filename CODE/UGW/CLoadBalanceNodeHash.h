// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************
#ifndef CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7
#define CLoadBalanceNodeHash_H_HEADER_INCLUDED_B3CA14F7

#include <string> 

namespace MyTENPAYAPI {
// 数据库hash算法接口，用于分布式资料库的离散存放与定位。
// 
// 关注三个纬度：node，database，table
//##ModelId=4C358A1503E0
class CLoadBalanceNodeHash
{
  public:
    // 初始化，使用一个字符串
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
