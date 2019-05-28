// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CTransactionFactory.h"

// 全局变量
std::map<string,MyCGI::CTransaction*(*)()> MyCGI::g_mCTransactionFactory;

std::map<std::string,MyCGI::CTransaction*> MyCGI::g_mCTransaction;

MyCGI::CTransactionFactory<MyCGI::CTransaction> MyCGI::g_CTransactionFactory("null");
