#include "CCgiIO.h"
// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CCOMMONCGIIO_H_HEADER_INCLUDED_B3EE244E
#define CCOMMONCGIIO_H_HEADER_INCLUDED_B3EE244E

#include "mysoft_cgi.h"

#include "CCgiIO.h"

namespace MyCGI {

//##ModelId=4C0C70D700B8
class CCommonCgiIO : public CCgiIO
{
  public:
    //##ModelId=4C11D65403C8
    virtual std::string getenv(const char *inName);

    //##ModelId=4C11D68802BF
    virtual std::string getenv(const string &inName);

    //##ModelId=4C11D71F034B
    CCommonCgiIO();

    //##ModelId=4C11D71F035B
    virtual ~CCommonCgiIO();
	


};

} // namespace MyCGI



#endif /* CCOMMONCGIIO_H_HEADER_INCLUDED_B3EE244E */
