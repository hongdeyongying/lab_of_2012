// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CLoadBalanceNodeHashFactory.h"



// ȫ�ֱ���
std::map<std::string,MyTENPAYAPI::CLoadBalanceNodeHash*(*)()> MyTENPAYAPI::g_mCLoadBalanceNodeHashFactory;
std::map<std::string,MyTENPAYAPI::CLoadBalanceNodeHash*> MyTENPAYAPI::g_mCLoadBalanceNodeHash;


MyTENPAYAPI::CLoadBalanceNodeHashFactory<MyTENPAYAPI::CLoadBalanceNodeHash> MyTENPAYAPI::g_CLoadBalanceNodeHashFactory("fix");




