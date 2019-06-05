#include "CChecker.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCHECKER_REGX_H_HEADER_INCLUDED_B3EE50EA
#define CCHECKER_REGX_H_HEADER_INCLUDED_B3EE50EA

#include "CCheckerFactory.h"

namespace MyCGI {

// ������ʽ���
//##ModelId=4BF65E2D01FE
class CChecker_Regx : public CChecker
{
  public:
    //##ModelId=4C11DBD10398
    virtual bool DoSingle(const std::string &inVal,const std::string &inFmt);

    //##ModelId=4C11DBD103D6
    virtual bool DoSingle(const MyUtility::CStringVector &inVal,const std::string &inFmt);

    //##ModelId=4C11DBD2001D
    virtual bool DoComplex(const std::string &inVal, const MyUtility::CStringMap &inOthers,const std::string &inFmt);

    //##ModelId=4C11DBD2003D
    virtual bool DoComplex(const MyUtility::CStringVector &inVal, const MyUtility::CStringVectorMap &inOthers,const std::string &inFmt);

};

} // namespace MyCGI



#endif /* CCHECKER_REGX_H_HEADER_INCLUDED_B3EE50EA */
