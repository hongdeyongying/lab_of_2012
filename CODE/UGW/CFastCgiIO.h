#include "CCgiIO.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CFASTCGIIO_H_HEADER_INCLUDED_B3EE4454
#define CFASTCGIIO_H_HEADER_INCLUDED_B3EE4454

#include "mysoft_cgi.h"

#include "CCgiIO.h"

namespace MyCGI {

// Fastcgi IO object
// 
//##ModelId=4C0C70EB00E8
class CFastCgiIO : public CCgiIO
{
  public:
    //##ModelId=4C11D56E02FD
    virtual size_t read(char *outDat, size_t inLen);

    //##ModelId=4C11D5730148
    virtual std::string getenv(const char *inName);

    //##ModelId=4C11D5890167
    std::ostream &err();

    //##ModelId=4C11D5CF0138
    CFastCgiIO(const CFastCgiIO &inIO);

    //##ModelId=4C11D5CF0157
    virtual ~CFastCgiIO();

    //##ModelId=4C11D601002E
    CFastCgiIO(FCGX_Request &inRequest);
	
protected:
    FCGX_Request& 			fRequest;
    fcgi_streambuf 			fOutBuf;
    fcgi_streambuf 			fErrBuf;
    std::ostream 			fErr;
};

} // namespace MyCGI



#endif /* CFASTCGIIO_H_HEADER_INCLUDED_B3EE4454 */
