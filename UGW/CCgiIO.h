// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CCGIIO_H_HEADER_INCLUDED_B3EE0BB1
#define CCGIIO_H_HEADER_INCLUDED_B3EE0BB1

#include "mysoft_cgi.h"


#include "cgicc/CgiInput.h"

namespace MyCGI {

//##ModelId=4C0C714F020A
class CCgiIO : public cgicc::CgiInput, public std::ostream

{
  public:
    //##ModelId=4C0C72E302A1
    virtual size_t read(char *outDat, size_t inLen);

    //##ModelId=4C0C739002E6
    virtual std::string getenv(const char *inName);

    virtual MyUtility::CStringMap & GetEnv()
	{
		return m_mEnv;
	}

    //##ModelId=4C0C73C302D8
    CCgiIO();

    //##ModelId=4C0C73EB0366
    virtual ~CCgiIO();

    //##ModelId=4C0C73EB03A5
    int operator==(const CCgiIO& right);

    //##ModelId=4C0C73EC0049
    int operator!=(const CCgiIO& right);

    //##ModelId=4C0C7BDF0089
    CCgiIO& operator=(const CCgiIO& right);

    //##ModelId=4C0C7C2200E9
    CCgiIO(const CCgiIO &input);
    CCgiIO(const CCgiIO &input,std::streambuf & buf);
    CCgiIO(std::streambuf & buf);
    CCgiIO(const CCgiIO &input,std::streambuf & buf,const MyUtility::CStringMap & env);

  protected:
	MyUtility::CStringMap 	m_mEnv;

};

} // namespace MyCGI



#endif /* CCGIIO_H_HEADER_INCLUDED_B3EE0BB1 */
