// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CTransactionFactory.h"

// ȫ�ֱ���
std::map<string,MyCGI::CTransaction*(*)()> MyCGI::g_mCTransactionFactory;

std::map<std::string,MyCGI::CTransaction*> MyCGI::g_mCTransaction;

MyCGI::CTransactionFactory<MyCGI::CTransaction> MyCGI::g_CTransactionFactory("null");
