// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#include "CTransaction_TEST.h"

#include "CTransactionFactory.h"

//##ModelId=4C11DABC033C
int MyCGI::CTransaction_TEST::Do(const MyUtility::CStringVectorMap &inPara, MyUtility::CStringVectorMap& outPara) throw(MyUtility::CMyException)
{
	MyUtility::CStringVector sv;
///*
	MyUtility::CStringVectorMap::const_iterator iterVector ;	

		
	for(	iterVector = inPara.begin();
		iterVector != inPara.end();
		iterVector++)
	{
		outPara["FORM_ELE_" + iterVector->first] = iterVector->second;

		DEBUG_LOGER  ;
	}

//*/	
	//outPara = inPara;
	
	sv.push_back("00");
	
	outPara["retcode"] = sv;
	
	
	sv[0] = "ok";
	
	outPara["retmsg"] = sv;
	
	return 0;
}
int  MyCGI::CTransaction_TEST::Do(
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

	MyUtility::CStringVector sv;

	outPara = inPara;
	
	sv.push_back("0");
	
	outPara["retcode"] = sv;
	
	
	sv[0] = "ok";
	
	outPara["retmsg"] = sv;

	MyUtility::CStringMap::const_iterator iter ;

	for(	iter = inEnv.begin();
		iter != inEnv.end();
		iter++)
	{
		sv[0] = iter->second;
		outPara["ENV_" + iter->first] = sv;
	}


	for(	iter = inCookie.begin();
		iter != inCookie.end();
		iter++)
	{
		sv[0] = iter->second;
		outPara["COOKIE_" +iter->first] = sv;
	}
		
	MyUtility::CStringVectorMap::const_iterator iterVector ;	
	for(	iterVector = inFileData.begin();
		iterVector != inFileData.end();
		iterVector++)
	{
		outPara["FILE_DATA_" +iterVector->first] = iterVector->second;
	}
		
	for(	iterVector = inPara.begin();
		iterVector != inPara.end();
		iterVector++)
	{
		outPara["FORM_ELE_" +iterVector->first] = iterVector->second;
	}
	
	return result;
}


MyCGI::CTransactionFactory<MyCGI::CTransaction_TEST> for_CTransactionFactory_method("test");
