// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CConvertorFactory.h"

// ȫ�ֱ���
map<string,MyCGI::CConvertor*(*)()> MyCGI::g_mCConvertorFactory;
map<string,MyCGI::CConvertor*> MyCGI::g_mCConvertor;

MyCGI::CConvertorFactory<MyCGI::CConvertor> MyCGI::g_CConvertorFactory("null");

