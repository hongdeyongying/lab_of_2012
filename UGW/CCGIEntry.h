#include "CCgiIO.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCGIENTRY_H_HEADER_INCLUDED_B3EE49F8
#define CCGIENTRY_H_HEADER_INCLUDED_B3EE49F8

#include "mysoft_cgi.h"

//Fastcgi �Ŀ���ͷ�ļ�
#include "fcgio.h"
//Cgicc��ͷ�ļ�
#include "cgicc/CgiInput.h"
#include "cgicc/Cgicc.h"
//������ͷ�ļ�
#include "CCommandLineInfo.h"
//ֻ��ָ��
#include "CMySmartPoint.h"

#include "CMyException.h"

#include "CCgiIO.h"

#include "CConfigEntry.h"


namespace MyCGI {

// CGI������ࣺ
// 1.��������ģʽ����ȡ�������
// 2.������������ʽ
// 3.��֤����������Ч�ԣ�������
// 4.��鷢�𷽵�Ȩ��
// 5.��鷢�𷽵�����Ƶ��
// 6.������ط���
// 7.��֯�������
// 8.�����xml��html��redir�ȣ�
// 
const std::string sERROR_SYSTEM_INIT("99   ϵͳ����");

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
  
    // ��ʼҵ��������
    // 
    //common cgi
    //fast cgi
    //debug cgi
    //##ModelId=4C10B53902C2
    virtual void Start(int argc,char ** argv);

  protected:
    // ��ͨCGI��������
    //##ModelId=4C10B5920304
    virtual void Start_Common();

    // FAST CGI��������
    //##ModelId=4C10B5C0021E
    virtual void Start_Fast();

    // ���ص���ģʽ CGI��������
    //##ModelId=4C10B5CE00C7
    virtual void Start_Debug();

    // ��ȡ�������
    //##ModelId=4C11A65A01C8
    virtual void GetInput() throw(MyUtility::CMyException);

    // �����������ԡ���ʽ�����ݡ�
    // 
    // 1.�������������Լ��
    // 2.������飺���������͡�����
    // 3.���дʼ�飺���Σ�ɫ�飬���
    // 4.��ϼ�飺�����������飬���������ʽ
    //##ModelId=4C11A49B0096
    virtual bool CheckFormat() throw(MyUtility::CMyException);

    // 1.�����Ƿ�������
    // 2.�����Ƿ񱻴۸�
    //##ModelId=4C11A70E02CB
    virtual bool CheckIntegrality(bool request = true) throw(MyUtility::CMyException);

    // 5.ת�����Բ������н��������
    //##ModelId=4C11A67D00EE
    virtual void DoTranslate() throw(MyUtility::CMyException);

    // ��鷢��Ȩ�ޣ�
    // �����²����ж��Ƿ��д˹���Ȩ��
    // 1.cookie���Ƿ��½���Ƿ�������ڵ�
    // 2.IP���Ƿ񱾵����û����Ƿ��������
    // 3.mac:
    // 4.referer:
    // 5.agent
    //##ModelId=4C11A75C01C6
    virtual bool CheckPopedom() throw(MyUtility::CMyException);

    // �������´������жϴ��û���Ƶ���Ƿ�Ӧ������
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

    // 1.������������Լ��
    // 2.���������ʽ���
    // 3.���д˼��
    // 4.����������
    //##ModelId=4C11AACC0334
    virtual bool ValidOutput() throw(MyUtility::CMyException);

    // 5.ת�����Բ������н��������
    //##ModelId=4C11AB27023F
    virtual bool TranslateOutput() throw(MyUtility::CMyException);

    // 1.�����������ǩ��
    //##ModelId=4C11AB410202
    virtual bool SignOutput() throw(MyUtility::CMyException);

    // ֧�ָ�ֵ�滻�������滻��ѭ����ģ�����
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
