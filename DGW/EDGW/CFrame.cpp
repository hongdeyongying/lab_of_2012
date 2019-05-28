#include "CFrame.h"

//##ModelId=51F60BE7035B
CFrame::CFrame()
{
	m_epollhandler_listen = -1;
	
	m_epollhandler_work = -1;
	
	m_run_state = 0;
	
	m_vpCListener.clear();
	
	m_vpCWorker.clear();
	
	// 1. 加载配置文件
	LoadConfig();
	
	// 2. 创建监听者线程
	CreateListener();
	
	// 3. 创建工作者线程
	CreateWorker();
	
	// 4. 检查运行状态并报告
	CheckAndReport();
}


//##ModelId=51F60BE7037A
CFrame::~CFrame()
{
}


//##ModelId=51F60AFE0264
int CFrame::LoadConfig()
{
	if(MyUtility::g_objCCommandLineInfo.GetArgVal("CONFIG_FILE_PATH") == "")
		g_CConfigEntry.LoadConfig(CONFIG_FILE_PATH);
	else
		g_CConfigEntry.LoadConfig(MyUtility::g_objCCommandLineInfo.GetArgVal("CONFIG_FILE_PATH"));
	
	// 初始化日志
	LOG_INIT(g_CConfigEntry.GetService("CONTROLER").GetVarVal("log").c_str(),"EDGW",CLog::EDEBUG);
}

//##ModelId=51F60B3900DD
int CFrame::CreateListener()
{
	CListener * pCListener = new CListener(this);
	
	m_vpCListener.push_back(pCListener);
	
	pCListener->StartWork();
	
	return 0;
}

//##ModelId=51F60B520181
int CFrame::CreateWorker()
{
	int worker_number = atoi(g_CConfigEntry.GetService("WORKER").GetVarVal("number").c_str());
	
	for(int i=0;i<worker_number;i++)
	{
		CWorker * pCWorker = new CWorker(this);
	
		m_vpCWorker.push_back(pCWorker);
		
		pCWorker->StartWork();
	}
	
	return 0;
}

//##ModelId=51F60B7302F1
int CFrame::CheckAndReport()
{
	while(1)
	{
		sleep(1000);
		// 检查监听线程
		
		// 检查工作者线程
		
		// 报告状态
		LOG_DEBUG("No more exception have been found.");
	}
	
	return 0;
}

