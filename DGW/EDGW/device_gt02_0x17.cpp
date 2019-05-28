#ifndef DEVICE_GT02_0x17_CPP
#define DEVICE_GT02_0x17_CPP

#include "UMSPThread.h"
#include <string>
#include "gt02.h"


class CDeviceSt02CMD0x17:public CUMSPThread
{
public:
	int m_sock;
	std::string m_imei;
	std::vector<CGt02Position> m_vPosition;
	int m_intval;
	
		
	CDeviceSt02CMD0x17(int sock,const std::string & imei="123456789012345",int intv=10):m_sock(sock),m_imei(imei),m_intval(intv)
	{
		m_iState = THREAD_RUN;
		
	};

	virtual ~CDeviceSt02CMD0x17(){m_iState = THREAD_STOP;};
	
	bool IsRunning()
	{
		return (m_iState == THREAD_RUN);
	};
protected:

	void Run()
	{
		char szBuf[1024];

		int nread = 0;
		
		while(m_iState != THREAD_STOP)
		{
			nread = read(m_sock,szBuf,1);

			if(nread > 0)
				fprintf(stderr,"%02x",szBuf[0]);
				
		}
		
		

	}
};



#endif //DEVICE_GT02_0x17_CPP
