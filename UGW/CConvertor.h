// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCONVERTOR_H_HEADER_INCLUDED_B3EE0B31
#define CCONVERTOR_H_HEADER_INCLUDED_B3EE0B31

#include "mysoft_cgi.h"

namespace MyCGI {

//##ModelId=4BF9F4BD01B9
class CConvertor
{
  public:
    //##ModelId=4C11DB8401FF
    virtual bool DoComplex(std::string &ioVal, const MyUtility::CStringMap &inOthers, const std::string &inMethod);

    //##ModelId=4C11DB84023E
    virtual bool DoComplex(MyUtility::CStringVector &inVal, MyUtility::CStringVectorMap &inOthers, const std::string &inMethod);

    //##ModelId=4C11DB84027C
    virtual bool DoSingle(std::string &inVal, const std::string &inMethod);

    //##ModelId=4C11DB84029C
    virtual bool DoSingle(MyUtility::CStringVector &inVal, const std::string &inMethod);

	virtual ~CConvertor(){};
};

} // namespace MyCGI



#endif /* CCONVERTOR_H_HEADER_INCLUDED_B3EE0B31 */
