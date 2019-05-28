// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CLoadBalanceNodeHashFactory.h"



// 全局变量
std::map<std::string,MyTENPAYAPI::CLoadBalanceNodeHash*(*)()> MyTENPAYAPI::g_mCLoadBalanceNodeHashFactory;
std::map<std::string,MyTENPAYAPI::CLoadBalanceNodeHash*> MyTENPAYAPI::g_mCLoadBalanceNodeHash;


MyTENPAYAPI::CLoadBalanceNodeHashFactory<MyTENPAYAPI::CLoadBalanceNodeHash> MyTENPAYAPI::g_CLoadBalanceNodeHashFactory("fix");




