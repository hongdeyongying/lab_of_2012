// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************
#include "CLoadBalanceNodeHash.h"

//##ModelId=4C3595FD02D5
void MyTENPAYAPI::CLoadBalanceNodeHash::Init(const std::string &inPara)
{
	
}

//##ModelId=4C3598580183
MyTENPAYAPI::CLoadBalanceNodeHash::CLoadBalanceNodeHash():m_sNodePostfix("")
{
}


//##ModelId=4C35985801E1
MyTENPAYAPI::CLoadBalanceNodeHash::~CLoadBalanceNodeHash()
{
}

//##ModelId=4C359858024F
const std::string &MyTENPAYAPI::CLoadBalanceNodeHash::GetNodePostfix() const
{
    return m_sNodePostfix;
}


//##ModelId=4C359858027D
const std::string & MyTENPAYAPI::CLoadBalanceNodeHash::GetNodePostfix(const std::string &inPara) 
{
	Init(inPara);
    return m_sNodePostfix;
}
