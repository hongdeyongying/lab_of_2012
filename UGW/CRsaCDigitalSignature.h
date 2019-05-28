#include "CDigitalSignature.h"
// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CRSACDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D563A6
#define CRSACDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D563A6
#include "CDigitalSignatureFactory.h"
namespace MyCGI {

//##ModelId=4BF65FFA026E
class CRsaCDigitalSignature : public CDigitalSignature
{
  public:
    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE79D02FE
    virtual bool Verify(const MyUtility::CStringVectorMap &inParas);

    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE79D031D
    virtual bool Verify(const std::string &inSrc, const std::string &inRes);

    // 签名成功返回true，否则返回false
    //##ModelId=4C2AE79D033D
    virtual bool Sign(MyUtility::CStringVectorMap &ioParas);

    // 如果验证成功返回true，否则返回false
    //##ModelId=4C2AE79D034C
    virtual bool Sign(const std::string &inSrc, std::string &outRes);

};

} // namespace MyCGI



#endif /* CRSACDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D563A6 */
