// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "mysoft_cgi.h"


const char * g_pszTransactionID_name = "tid";

//ϵͳ�����Ĺؼ���
//const std::string sRESERVED_VAR_NAME_OUTPUT_TEMPLATE("_output_template");
const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY("_request_verifier");
const std::string sRESERVED_VAR_NAME_REQUEST_VERIFY_KEY("_request_verifier_key");
const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER("_response_signer");
const std::string sRESERVED_VAR_NAME_RESPONSE_SIGNER_KEY("_response_signer_key");
const std::string sINTEGRALITY_CHECK_REQUEST("_request_integrality");
const std::string sINTEGRALITY_CHECK_RESPONSE("_response_integrality");

// Ψһʵ��
const std::string sSINGLETON_TRANSACTION_FLAG("_singleton_flag");


//�����붨��
//�����ļ�����
const long iPREPARE_CONFIG_ERROR = 10000001;
const long iEXECUTE_CONFIG_ERROR = 20000001;
//��ʽ����
const long iINPUT_FORMAT_ERROR = 10000002;
const long iOUTPUT_FORMAT_ERROR = 20000002;
//Ҫ��ȱ��
const long iINPUT_ELEMENT_LACK = 10000003;
const long iOUTPUT_ELEMENT_LACK = 20000003;
//Ҫ�ض���
const long iINPUT_ELEMENT_MORE = 10000004;
const long iOUTPUT_ELEMENT_MORE = 20000004;
//������Ч��֤ǩ��
const long iINPUT_VERIFY_INVALID = 10000005;
//���ǩ��ʧ��
const long iOUTPUT_SIGN_ERROR = 20000005;



const std::string sENV_HEADER("ENV_HEADER_");
const std::string sCK_HEADER("CK_HEADER_");
const std::string sFILE_HEADER("FILE_HEADER_");


// ������ģ�涨��
const std::string sERROR_TEMPLATE_CONFIG("_error_config");
const std::string sTEMPLATE_DEFAULT("default");
const std::string sSERVICE_TEMPLATE_PREFIX("_output_template_");


