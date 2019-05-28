#include "CDigitalSignature.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CRSACDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D563A6
#define CRSACDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D563A6
#include "CDigitalSignatureFactory.h"
namespace MyCGI {

//##ModelId=4BF65FFA026E
class CRsaCDigitalSignature : public CDigitalSignature
{
  public:
    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE79D02FE
    virtual bool Verify(const MyUtility::CStringVectorMap &inParas);

    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE79D031D
    virtual bool Verify(const std::string &inSrc, const std::string &inRes);

    // ǩ���ɹ�����true�����򷵻�false
    //##ModelId=4C2AE79D033D
    virtual bool Sign(MyUtility::CStringVectorMap &ioParas);

    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE79D034C
    virtual bool Sign(const std::string &inSrc, std::string &outRes);

};

} // namespace MyCGI



#endif /* CRSACDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D563A6 */
