// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D56A2C
#define CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D56A2C

#include "mysoft_cgi.h"

namespace MyCGI {

// ����ǩ�������ӿ��࣬�ṩ��������
// verify
//   in : stringvectormap/string string/
//   out: bool
// 
// sign
//   io : stringvectormap/in string  out string
//   out: bool
//##ModelId=4BF65FD503E3
class CDigitalSignature
{
  public:
    virtual void SetParas(const MyUtility::CStringVector & right)
    {
    	m_vParas = right;
    }
    virtual MyUtility::CStringVector & GetParas()
    {
    	return m_vParas;
    }
    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE4FC00F8
    virtual bool Verify(const MyUtility::CStringVectorMap &inParas);

    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE54E01D6
    virtual bool Verify(const std::string &inSrc, const std::string &inRes);

    // ǩ���ɹ�����true�����򷵻�false
    //##ModelId=4C2AE5930274
    virtual bool Sign(MyUtility::CStringVectorMap &ioParas);

    // �����֤�ɹ�����true�����򷵻�false
    //##ModelId=4C2AE5D303BD
    virtual bool Sign(const std::string &inSrc, std::string &outRes);


	virtual ~CDigitalSignature(){};	
	
  protected:
    MyUtility::CStringVector m_vParas;

};

} // namespace MyCGI



#endif /* CDIGITALSIGNATURE_H_HEADER_INCLUDED_B3D56A2C */
