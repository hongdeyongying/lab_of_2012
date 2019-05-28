// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CTransaction.h"

//##ModelId=4C11B0E100F7
int MyCGI::CTransaction::Do(const MyUtility::CStringVectorMap &inPara, MyUtility::CStringVectorMap& outPara) throw(MyUtility::CMyException)
{
	int result = 0;
	   
	
	return result;
}


int  MyCGI::CTransaction::Do(
        // 输入参数
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // 输出参数
        MyUtility::CStringVectorMap& outPara,
        //配置文件
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException)
{
	int result = 0;
	   
	
	return result;
}

