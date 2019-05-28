// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CDatabaseHashFactory.h"



// 全局变量
std::map<std::string,MyAPP::CDatabaseHash*(*)()> MyAPP::g_mCDatabaseHashFactory;
std::map<std::string,MyAPP::CDatabaseHash*> MyAPP::g_mCDatabaseHash;


MyAPP::CDatabaseHashFactory<MyAPP::CDatabaseHash> MyAPP::g_CDatabaseHashFactory("fix");




