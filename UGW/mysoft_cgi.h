// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef MYSOFT_CGI_H_HEADER_INCLUDED_B3FA158B
#define MYSOFT_CGI_H_HEADER_INCLUDED_B3FA158B

#pragma warning(disable:4786) 
#pragma warning(disable:4530)

#define ASSERT(expr) assert(expr)

#include <assert.h>

#include <string>
#include <set>
#include <map>
#include <vector>

#include <algorithm>


#include <iostream>
#include <cstdlib>

using namespace std;

#include "fcgio.h"

#ifndef         WIN32
typedef long LONG;
#endif

#ifdef _WIN32
#include <process.h>
#else
#ifndef __USE_GNU
#define __USE_GNU
extern char ** environ;
#endif
#endif



#include "CStringVectorMap.h"
#include "CMyException.h"
#include "CStringMap.h"
#include "CStringVector.h"
#include "CMySmartPoint.h"

#include "CMyLogApi.h"


#ifdef WIN32
#include <windows.h>
#endif

#include <cstdlib>

//

// �����Ψһ��־
extern const char * g_pszTransactionID_name;

//ϵͳ�����Ĺؼ���
extern const std::string sRESERVED_VAR_NAME_OUTPUT_TEMPLATE;
extern const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY;
extern const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY;
extern const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER;
extern const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER_KEY;
extern const std::string sINTEGRALITY_CHECK_REQUEST;
extern const std::string sINTEGRALITY_CHECK_RESPONSE;
extern const std::string sSINGLETON_TRANSACTION_FLAG;

//�����붨��
//�����ļ�����
extern const long iPREPARE_CONFIG_ERROR ;
extern const long iEXECUTE_CONFIG_ERROR ;
//��ʽ����
extern const long iINPUT_FORMAT_ERROR ;
extern const long iOUTPUT_FORMAT_ERROR ;
//Ҫ��ȱ��
extern const long iINPUT_ELEMENT_LACK ;
extern const long iOUTPUT_ELEMENT_LACK ;
//Ҫ�ض���
extern const long iINPUT_ELEMENT_MORE ;
extern const long iOUTPUT_ELEMENT_MORE ;
//������Ч��֤ǩ��
extern const long iINPUT_VERIFY_INVALID ;
//���ǩ��ʧ��
extern const long iOUTPUT_SIGN_ERROR ;

//
extern const std::string sENV_HEADER;
extern const std::string sCK_HEADER;
extern const std::string sFILE_HEADER;


// ������ģ�涨��
extern const std::string sERROR_TEMPLATE_CONFIG;	// ������ģ�������
extern const std::string sTEMPLATE_DEFAULT;			// ������ģ��ȱʡ����
extern const std::string sSERVICE_TEMPLATE_PREFIX;	// �����������ģ���ǰ׺

#endif /* MYSOFT_CGI_H_HEADER_INCLUDED_B3FA158B */
