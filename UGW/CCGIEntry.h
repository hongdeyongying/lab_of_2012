#include "CCgiIO.h"
// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CCGIENTRY_H_HEADER_INCLUDED_B3EE49F8
#define CCGIENTRY_H_HEADER_INCLUDED_B3EE49F8

#include "mysoft_cgi.h"

//Fastcgi 的开发头文件
#include "fcgio.h"
//Cgicc的头文件
#include "cgicc/CgiInput.h"
#include "cgicc/Cgicc.h"
//命令行头文件
#include "CCommandLineInfo.h"
//只能指针
#include "CMySmartPoint.h"

#include "CMyException.h"

#include "CCgiIO.h"

#include "CConfigEntry.h"


namespace MyCGI {

// CGI的入口类：
// 1.根据启动模式，读取输入参数
// 2.检查输入参数格式
// 3.验证输入请求有效性，完整性
// 4.检查发起方的权限
// 5.检查发起方的请求频次
// 6.调用相关服务
// 7.组织输出数据
// 8.输出（xml、html、redir等）
// 
const std::string sERROR_SYSTEM_INIT("99   系统错误");

#ifndef DEFAULT_CONFIG_FILEPATH 
	#define DEFAULT_CONFIG_FILEPATH "../cnf/MyCGI.conf.index.xml"
#endif

//##ModelId=4BF6301202F6
class CCGIEntry
{
  private:
	 // std::string sSERVICE_CONFIGFILE_PATH;
	  //std::string sELEMENT_CONFIGFILE_PATH;
	  std::string sCONFIGFILE_PATH;
 
 
  public:
	CCGIEntry():m_pCCgiIO(NULL),m_pCgicc(NULL),m_ci(MyUtility::g_objCCommandLineInfo)
	{
		// cgi -f in.dat -r login -d
		// cgi /f in.dat /r login /d
		// cgi --file=in.dat --request=login --debug
		m_ci.AddEntry("file","-f",DEFAULT_CONFIG_FILEPATH,false,true);
		m_ci.AddEntry("file","--file=","");
		m_ci.AddEntry("file","/f","",false);
		m_ci.AddEntry("file","/f:","",false);
		
		m_ci.AddEntry("request","-r","",false);
		m_ci.AddEntry("request","--request=","");
		m_ci.AddEntry("request","/r","",false);
		m_ci.AddEntry("request","/r:","",false);
				
		m_ci.AddEntry("config","-c",DEFAULT_CONFIG_FILEPATH,false);
		m_ci.AddEntry("config","--config=","");
		m_ci.AddEntry("config","/c","",false);
		m_ci.AddEntry("config","/c:","",false);
		
		m_ci.AddEntry("debug","-d","off",true);
		m_ci.AddEntry("debug","--debug","off",true);
		m_ci.AddEntry("debug","/d","off",true);
		
		
		m_mInPara.clear();
		
		m_mOutPara.clear();
		
		
		//sSERVICE_CONFIGFILE_PATH = ("../conf/service.conf.xml");
		//sELEMENT_CONFIGFILE_PATH = ("../conf/element.conf.xml");
		sCONFIGFILE_PATH = DEFAULT_CONFIG_FILEPATH;
	};
  
    // 开始业务处理流程
    // 
    //common cgi
    //fast cgi
    //debug cgi
    //##ModelId=4C10B53902C2
    virtual void Start(int argc,char ** argv);

  protected:
    // 普通CGI处理流程
    //##ModelId=4C10B5920304
    virtual void Start_Common();

    // FAST CGI处理流程
    //##ModelId=4C10B5C0021E
    virtual void Start_Fast();

    // 本地调试模式 CGI处理流程
    //##ModelId=4C10B5CE00C7
    virtual void Start_Debug();

    // 读取输入参数
    //##ModelId=4C11A65A01C8
    virtual void GetInput() throw(MyUtility::CMyException);

    // 检查参数存在性、格式、内容。
    // 
    // 1.单个参数存在性检查
    // 2.基本检查：参数的类型、长度
    // 3.敏感词检查：政治，色情，脏词
    // 4.组合检查：多参数条件检查，存在性与格式
    //##ModelId=4C11A49B0096
    virtual bool CheckFormat() throw(MyUtility::CMyException);

    // 1.请求是否接收完毕
    // 2.请求是否被篡改
    //##ModelId=4C11A70E02CB
    virtual bool CheckIntegrality(bool request = true) throw(MyUtility::CMyException);

    // 5.转换：对参数进行解码与编码
    //##ModelId=4C11A67D00EE
    virtual void DoTranslate() throw(MyUtility::CMyException);

    // 检查发起方权限：
    // 据如下参数判断是否有此功能权限
    // 1.cookie：是否登陆，是否黑名单节点
    // 2.IP：是否本地域用户，是否黑名单等
    // 3.mac:
    // 4.referer:
    // 5.agent
    //##ModelId=4C11A75C01C6
    virtual bool CheckPopedom() throw(MyUtility::CMyException);

    // 根据如下从那数判断此用户的频率是否应该受限
    // 1.ip
    // 2.cookie
    // 3.mac
    //##ModelId=4C11A7D00303
    virtual bool CheckFrequence() throw(MyUtility::CMyException);

    // 
    // {
    //     CTrans *pTrans = CreateHander(sid);
    // 
    //     CMySmartPoint<CTrans> p(pTrans);
    // 
    //     return p->Do(inPara,outPara);
    // }
    //##ModelId=4C11A80801FB
    virtual int CommitTrans() throw(MyUtility::CMyException);

    // 1.输出参数存在性检查
    // 2.输出参数格式检查
    // 3.敏感此检查
    // 4.组合条件检查
    //##ModelId=4C11AACC0334
    virtual bool ValidOutput() throw(MyUtility::CMyException);

    // 5.转换：对参数进行解码与编码
    //##ModelId=4C11AB27023F
    virtual bool TranslateOutput() throw(MyUtility::CMyException);

    // 1.对输出参数的签名
    //##ModelId=4C11AB410202
    virtual bool SignOutput() throw(MyUtility::CMyException);

    // 支持赋值替换、条件替换、循环的模版输出
    //##ModelId=4C11AB600213
    virtual void SetOupt() throw(MyUtility::CMyException);

    virtual void ErrorDump(MyUtility::CMyException & exp);	

    virtual const MyConfig::CConfigEntry & GetConfig() const 
    	{
    		return m_Config;
    	};
	virtual  MyConfig::CConfigEntry & GetConfig()  
    	{
    		return m_Config;
    	};

  private:
    //##ModelId=4C10BD76000F
    CCgiIO* m_pCCgiIO;
	
	cgicc::Cgicc * m_pCgicc;
	
	MyUtility::CCommandLineInfo &m_ci;

    //##ModelId=4C11A92D034A
    MyUtility::CStringVectorMap m_mInPara;
    MyUtility::CStringVectorMap m_mInFileData;
    MyUtility::CStringMap m_mInEnv;
    MyUtility::CStringMap m_mInCookie;

    //##ModelId=4C11A94801E3
    MyUtility::CStringVectorMap m_mOutPara;
	
	MyConfig::CConfigEntry m_Config;
	
	void InitLoger();
	void ClearLoger();

};

} // namespace MyCGI

extern MyCGI::CCGIEntry * g_CCGIEntry;



#endif /* CCGIENTRY_H_HEADER_INCLUDED_B3EE49F8 */
