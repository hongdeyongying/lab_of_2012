// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CConvertorFactory.h"

// 全局变量
map<string,MyCGI::CConvertor*(*)()> MyCGI::g_mCConvertorFactory;
map<string,MyCGI::CConvertor*> MyCGI::g_mCConvertor;

MyCGI::CConvertorFactory<MyCGI::CConvertor> MyCGI::g_CConvertorFactory("null");

