// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCONVERTOR_BASE_H_HEADER_INCLUDED_B3DFF70B
#define CCONVERTOR_BASE_H_HEADER_INCLUDED_B3DFF70B

#include "mysoft_cgi.h"

#include "CConvertor.h"


namespace MyCGI {

// �û����ı��������������
//##ModelId=4C11DC8602CB
class CConvertor_Base : public CConvertor
{
  public:
    //##ModelId=4C11DD69025B
    virtual bool DoComplex(std::string &ioVal, const MyUtility::CStringMap &inOthers, const std::string &inMethod);

    //##ModelId=4C11DD69028A
    virtual bool DoComplex(MyUtility::CStringVector &inVal, MyUtility::CStringVectorMap &inOthers, const std::string &inMethod);

    //##ModelId=4C11DD6902C8
    virtual bool DoSingle(std::string &inVal, const std::string &inMethod);

    //##ModelId=4C11DD6902D8
    virtual bool DoSingle(MyUtility::CStringVector &inVal, const std::string &inMethod);

};

//MyCGI::CConvertorFactory<MyCGI::CConvertor_Base> MyCGI::for_CConvertorFactory_method("base");
} // namespace MyCGI



#endif /* CCONVERTOR_BASE_H_HEADER_INCLUDED_B3DFF70B */
