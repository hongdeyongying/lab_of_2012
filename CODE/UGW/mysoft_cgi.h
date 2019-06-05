// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现基本格式转换，支持HTTP的解析与转换。  
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

// 服务的唯一标志
extern const char * g_pszTransactionID_name;

//系统保留的关键字
extern const std::string sRESERVED_VAR_NAME_OUTPUT_TEMPLATE;
extern const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY;
extern const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY;
extern const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER;
extern const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER_KEY;
extern const std::string sINTEGRALITY_CHECK_REQUEST;
extern const std::string sINTEGRALITY_CHECK_RESPONSE;
extern const std::string sSINGLETON_TRANSACTION_FLAG;

//错误码定义
//配置文件错误
extern const long iPREPARE_CONFIG_ERROR ;
extern const long iEXECUTE_CONFIG_ERROR ;
//格式错误
extern const long iINPUT_FORMAT_ERROR ;
extern const long iOUTPUT_FORMAT_ERROR ;
//要素缺少
extern const long iINPUT_ELEMENT_LACK ;
extern const long iOUTPUT_ELEMENT_LACK ;
//要素多余
extern const long iINPUT_ELEMENT_MORE ;
extern const long iOUTPUT_ELEMENT_MORE ;
//请求无效验证签名
extern const long iINPUT_VERIFY_INVALID ;
//输出签名失败
extern const long iOUTPUT_SIGN_ERROR ;

//
extern const std::string sENV_HEADER;
extern const std::string sCK_HEADER;
extern const std::string sFILE_HEADER;


// 错误处理模版定义
extern const std::string sERROR_TEMPLATE_CONFIG;	// 错误处理模版服务名
extern const std::string sTEMPLATE_DEFAULT;			// 错误处理模版缺省变量
extern const std::string sSERVICE_TEMPLATE_PREFIX;	// 服务输出处理模版的前缀

#endif /* MYSOFT_CGI_H_HEADER_INCLUDED_B3FA158B */
