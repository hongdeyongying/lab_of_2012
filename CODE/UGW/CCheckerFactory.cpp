// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CCheckerFactory.h"



// ȫ�ֱ���
std::map<std::string,MyCGI::CChecker*(*)()> MyCGI::g_mCCheckerFactory;
std::map<std::string,MyCGI::CChecker*> MyCGI::g_mCChecker;


MyCGI::CCheckerFactory<MyCGI::CChecker> MyCGI::g_CCheckerFactory("null");

 
