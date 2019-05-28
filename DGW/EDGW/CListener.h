#ifndef CLISTENER_H_HEADER_INCLUDED_AE09F229
#define CLISTENER_H_HEADER_INCLUDED_AE09F229



#include "gvar_edgw.h"

#include "UMSPThread.h"

class CFrame;

//##ModelId=51F616BF01C3
class CListener : public CUMSPThread
{
  public:
    //##ModelId=51F6172D01B0
    int Create(const char * service);

    //##ModelId=51F617B50377
    int WaitClient();

    //##ModelId=51F6184A03A8
    int Process(int sock);

    //##ModelId=51F6186101DE
    CListener();

    //##ModelId=51F6186101EE
    virtual ~CListener();

    //##ModelId=51F6191C0025
    CListener(CFrame *pCFrame);
	
	virtual void Run();
	
	// 0 normal ; 1 exit
	int m_iRunState;
  private:
    //##ModelId=51F619040106
    CFrame* m_pCFrame;
	
	struct epoll_event m_stEventList[MAX_EPOLL_FID];
	
};
#endif /* CLISTENER_H_HEADER_INCLUDED_AE09F229 */
