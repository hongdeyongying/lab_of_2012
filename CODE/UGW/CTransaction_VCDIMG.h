// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CTRANSACTION_VCDIMG_H_HEADER_INCLUDED_B3EE7263
#define CTRANSACTION_VCDIMG_H_HEADER_INCLUDED_B3EE7263

#include "mysoft_cgi.h"

#include "CTransaction.h"


namespace MyCGI {

// �����õĶ���
//##ModelId=4C11B36A03D2
class CTransaction_VCDIMG : public CTransaction
{
  public:
    virtual int Do(
        // �������
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // �������
        MyUtility::CStringVectorMap& outPara,
        MyConfig::CConfigEntry & config ) throw(MyUtility::CMyException);
};

} // namespace MyCGI



#endif /* CTRANSACTION_VCDIMG_H_HEADER_INCLUDED_B3EE7263 */
