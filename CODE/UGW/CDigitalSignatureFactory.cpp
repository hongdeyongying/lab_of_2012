// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CDigitalSignatureFactory.h"



// ȫ�ֱ���
std::map<std::string,MyCGI::CDigitalSignature*(*)()> MyCGI::g_mCDigitalSignatureFactory;
map<std::string,MyCGI::CDigitalSignature*> MyCGI::g_mCDigitalSignature;


MyCGI::CDigitalSignatureFactory<MyCGI::CDigitalSignature> MyCGI::g_CDigitalSignatureFactory("null");




