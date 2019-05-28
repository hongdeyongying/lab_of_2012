// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "mysoft_cgi.h"


const char * g_pszTransactionID_name = "tid";

//系统保留的关键字
//const std::string sRESERVED_VAR_NAME_OUTPUT_TEMPLATE("_output_template");
const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY("_request_verifier");
const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY("_request_verifier_key");
const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER("_response_signer");
const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER_KEY("_response_signer_key");
const std::string sINTEGRALITY_CHECK_REQUEST("_request_integrality");
const std::string sINTEGRALITY_CHECK_RESPONSE("_response_integrality");

// 唯一实例
const std::string sSINGLETON_TRANSACTION_FLAG("_singleton_flag");


//错误码定义
//配置文件错误
const long iPREPARE_CONFIG_ERROR = 10000001;
const long iEXECUTE_CONFIG_ERROR = 20000001;
//格式错误
const long iINPUT_FORMAT_ERROR = 10000002;
const long iOUTPUT_FORMAT_ERROR = 20000002;
//要素缺少
const long iINPUT_ELEMENT_LACK = 10000003;
const long iOUTPUT_ELEMENT_LACK = 20000003;
//要素多余
const long iINPUT_ELEMENT_MORE = 10000004;
const long iOUTPUT_ELEMENT_MORE = 20000004;
//请求无效验证签名
const long iINPUT_VERIFY_INVALID = 10000005;
//输出签名失败
const long iOUTPUT_SIGN_ERROR = 20000005;



const std::string sENV_HEADER("ENV_HEADER_");
const std::string sCK_HEADER("CK_HEADER_");
const std::string sFILE_HEADER("FILE_HEADER_");


// 错误处理模版定义
const std::string sERROR_TEMPLATE_CONFIG("_error_config");
const std::string sTEMPLATE_DEFAULT("default");
const std::string sSERVICE_TEMPLATE_PREFIX("_output_template_");


