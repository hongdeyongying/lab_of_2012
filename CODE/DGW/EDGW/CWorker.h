#ifndef CWORKER_H_HEADER_INCLUDED_AE098711
#define CWORKER_H_HEADER_INCLUDED_AE098711
class CFrame;
#include "gvar_edgw.h"

class CMyMutex
{
	private:
		CUMSPThread *m_pWorker;
		int m_iLockID;
	public:
		CMyMutex(CUMSPThread *pWorker,int inLockID=0):m_iLockID(inLockID){m_pWorker = pWorker;m_pWorker->Lock(m_iLockID);}
		~CMyMutex(){m_pWorker->UnLock(m_iLockID);};
};

//##ModelId=51F60C5E03E4
class CWorker : public CUMSPThread
{
  public:
    //##ModelId=51F60CE60230
    virtual int WaitAndRecvData(int sfd);

    //##ModelId=51F60D940158
    virtual int Process(const std::string &sInput, std::string &sOutput);
    //##ModelId=51F615FF0289
    virtual ~CWorker();

    //##ModelId=51F618A302EB
    CWorker(CFrame *pCFrame);
	
	virtual void Run();

  private:
    //##ModelId=51F6187B0398
    CFrame *m_pCFrame;
	
	unsigned char m_szBuf[BUF_SIZE];

	struct epoll_event m_stEventList[MAX_EPOLL_FID];
};

#endif /* CWORKER_H_HEADER_INCLUDED_AE098711 */
