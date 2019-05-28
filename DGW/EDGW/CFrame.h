#ifndef CFRAME_H_HEADER_INCLUDED_AE09A304
#define CFRAME_H_HEADER_INCLUDED_AE09A304

// 主线程：
//   配置文件读取，加载SO，启动数据监听线程，启动工作者线程，定期检查服务状态，输出
// 
// 
// 
//##ModelId=51F5E09200FC
#include "gvar_edgw.h"

#include "CListener.h"
#include "CWorker.h"
#include <vector>
class CFrame
{
  public:
    //##ModelId=51F60BE7035B
    CFrame();

    //##ModelId=51F60BE7037A
    virtual ~CFrame();
	
	int &GetListenHandler() {return m_epollhandler_listen;}
	int &GetWorkHandler() {return m_epollhandler_work;}
	int &GetRunState() {return m_run_state;}

  private:
    //##ModelId=51F60AFE0264
    int LoadConfig();

    //##ModelId=51F60B3900DD
    int CreateListener();

    //##ModelId=51F60B520181
    int CreateWorker();

    //##ModelId=51F60B7302F1
    int CheckAndReport();

    //##ModelId=51F6182A03B4
    int m_epollhandler_listen;

    //##ModelId=51F6182A03C3
    int m_epollhandler_work;
	
	// run state : 0 normal 1 exit
	int m_run_state;
	
	std::vector<CListener *> m_vpCListener;
	std::vector<CWorker *> m_vpCWorker;

};



#endif /* CFRAME_H_HEADER_INCLUDED_AE09A304 */
