#include "CCgiIO.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
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
