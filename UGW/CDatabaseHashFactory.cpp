// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CDatabaseHashFactory.h"



// ȫ�ֱ���
std::map<std::string,MyAPP::CDatabaseHash*(*)()> MyAPP::g_mCDatabaseHashFactory;
std::map<std::string,MyAPP::CDatabaseHash*> MyAPP::g_mCDatabaseHash;


MyAPP::CDatabaseHashFactory<MyAPP::CDatabaseHash> MyAPP::g_CDatabaseHashFactory("fix");




