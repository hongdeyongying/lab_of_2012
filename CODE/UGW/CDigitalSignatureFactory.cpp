// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CDigitalSignatureFactory.h"



// 全局变量
std::map<std::string,MyCGI::CDigitalSignature*(*)()> MyCGI::g_mCDigitalSignatureFactory;
map<std::string,MyCGI::CDigitalSignature*> MyCGI::g_mCDigitalSignature;


MyCGI::CDigitalSignatureFactory<MyCGI::CDigitalSignature> MyCGI::g_CDigitalSignatureFactory("null");




