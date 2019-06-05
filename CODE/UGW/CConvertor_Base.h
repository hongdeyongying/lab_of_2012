// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CCONVERTOR_BASE_H_HEADER_INCLUDED_B3DFF70B
#define CCONVERTOR_BASE_H_HEADER_INCLUDED_B3DFF70B

#include "mysoft_cgi.h"

#include "CConvertor.h"


namespace MyCGI {

// 用基本的编码解码来做解析
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
