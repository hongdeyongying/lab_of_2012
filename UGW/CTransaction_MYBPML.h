// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CTRANSACTION_MYBPML_H_HEADER_INCLUDED_B3EE7263
#define CTRANSACTION_MYBPML_H_HEADER_INCLUDED_B3EE7263

#include "mysoft_cgi.h"

#include "CTransaction.h"

//#include <mysql++.h>

#include "CConfigEntry.h"

#include "CBaseEncode.h"

namespace MyAPP {

// �����õĶ���
//##ModelId=4C11B36A03D2
class CTransaction_MYBPML : public MyCGI::CTransaction
{
  private:

  public:
	CTransaction_MYBPML();
	virtual ~CTransaction_MYBPML();
  
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
		//�����ļ�
		MyConfig::CConfigEntry & config) throw(MyUtility::CMyException);
};

} // namespace MyAPP



#endif /* CTRANSACTION_MYBPML_H_HEADER_INCLUDED_B3EE7263 */
