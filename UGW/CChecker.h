// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCHECKER_H_HEADER_INCLUDED_B3EE6386
#define CCHECKER_H_HEADER_INCLUDED_B3EE6386
#include "mysoft_cgi.h"
namespace MyCGI {


const std::string sCHECKER_METHOD_SINGLE( "single");
const std::string sCHECKER_METHOD_COMPLEX( "complex");

//##ModelId=4BF65E130382
class CChecker
{
  public:
    //##ModelId=4C11D76801E4
    virtual bool DoSingle(const std::string &inVal,const std::string &inFmt);

    //##ModelId=4C11D8E1019E
    virtual bool DoSingle(const MyUtility::CStringVector &inVal,const std::string &inFmt);

    //##ModelId=4C11D9110304
    virtual bool DoComplex(const std::string &inVal, const MyUtility::CStringMap &inOthers,const std::string &inFmt);

    //##ModelId=4C11D9110371
    virtual bool DoComplex(const MyUtility::CStringVector &inVal, const MyUtility::CStringVectorMap &inOthers,const std::string &inFmt);


	virtual ~CChecker(){};
};

} // namespace MyCGI



#endif /* CCHECKER_H_HEADER_INCLUDED_B3EE6386 */
