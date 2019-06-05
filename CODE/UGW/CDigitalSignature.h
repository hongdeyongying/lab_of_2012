// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D56A2C
#define CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D56A2C

#include "mysoft_cgi.h"

namespace MyCGI {

// 数字签名基础接口类，提供两个方法
// verify
//   in : stringvectormap/string string/
//   out: bool
// 
// sign
//   io : stringvectormap/in string  out string
//   out: bool
//##ModelId=4BF65FD503E3
class CDigitalSignature
{
  public:
    virtual void SetParas(const MyUtility::CStringVector & right)
    {
    	m_vParas = right;
    }
    virtual MyUtility::CStringVector & GetParas()
    {
    	return m_vParas;
    }
    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE4FC00F8
    virtual bool Verify(const MyUtility::CStringVectorMap &inParas);

    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE54E01D6
    virtual bool Verify(const std::string &inSrc, const std::string &inRes);

    // 签名成功返回true，否则返回false
    //##ModelId=4C2AE5930274
    virtual bool Sign(MyUtility::CStringVectorMap &ioParas);

    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE5D303BD
    virtual bool Sign(const std::string &inSrc, std::string &outRes);


	virtual ~CDigitalSignature(){};	
	
  protected:
    MyUtility::CStringVector m_vParas;

};

} // namespace MyCGI



#endif /* CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D56A2C */
