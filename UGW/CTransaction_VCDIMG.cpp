// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CTransaction_VCDIMG.h"

#include "CTransactionFactory.h"


#include "CVcdImg.h"


int  MyCGI::CTransaction_VCDIMG::Do(
        // �������
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // �������
        MyUtility::CStringVectorMap& outPara,
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException)
{
	int result = 0;
	LOGER_DEBUG << LOGER_ETAG;

	MyUtility::CStringVector sv;

	CVcdImg objCVcdImg;

	std::string sVcdMd5,sImg;

	result = objCVcdImg.Get(sVcdMd5,sImg);

	LOGER_DEBUG << result <<LOGER_ETAG;
	
	if( result == 0)
	{
		
		sv.push_back("0");
	
		outPara["retcode"] = sv;
		
		
		sv[0] = "ok";
		
		outPara["retmsg"] = sv;

		//LOGER_DEBUG << LOGER_ETAG;
		outPara["vcdmd5"].push_back(sVcdMd5);
		outPara["vcdimg"].push_back(sImg);
		//LOGER_DEBUG << LOGER_ETAG;
	}
	else
	{
		
		sv.push_back("90000");
	
		outPara["retcode"] = sv;
		
		
		sv[0] = "vcdimg generate error  ";
		
		outPara["retmsg"] = sv;
	}

	
	return result;
}


static MyCGI::CTransactionFactory<MyCGI::CTransaction_VCDIMG> for_CTransactionFactory_method("vcdimg");

