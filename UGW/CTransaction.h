// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CTRANSACTION_H_HEADER_INCLUDED_B3EE21B4
#define CTRANSACTION_H_HEADER_INCLUDED_B3EE21B4

#include "mysoft_cgi.h"
#include "CConfigEntry.h"

#define ERROR_RETURN(retcd,retmsg,res) {res["retcode"].push_back(retcd);res["retmsg"].push_back(retmsg);return atoi(retcd);}

namespace MyCGI {

// ҵ���ύ����������ҵ��������������
//##ModelId=4C11B0C8023F
class CTransaction
{
  public:
  	CTransaction(){};
  	virtual ~CTransaction(){};
    // �ύ���ף�����һ������ֵ�����׳��쳣
    //##ModelId=4C11B0E100F7
    virtual int Do(
        // �������
        const MyUtility::CStringVectorMap &inPara, 
        // �������
        MyUtility::CStringVectorMap& outPara) throw(MyUtility::CMyException);
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
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException);

};

} // namespace MyCGI



#endif /* CTRANSACTION_H_HEADER_INCLUDED_B3EE21B4 */
