#include "CWorker.h"
#include "CFrame.h"

#include "gt02.h"

#include <sstream>

#include "CLDDGt02.h"

static CLDDGt02 objCLDDGt02;


void CWorker::Run()
{
	// 抢占式监听
	int wait_res = 0;
	int sock = -1;

	//
	{
		CMyMutex t_CMyMutex(this,1);
		int iRet = objCLDDGt02.Init(10000,0); 
		if ( 0 != iRet)
		{
			LOG_ERROR("Init mmap for LDD error . %d retcode %d!!! \r\n",syscall(SYS_gettid),iRet);
			return;
		}
		else
		{
			LOG_ERROR("Init mmap for LDD ok . %d retcode %d!!! \r\n",syscall(SYS_gettid),iRet);
		}
	}
	
	while(m_pCFrame->GetRunState() == 0)
	{				
		{
			CMyMutex t_CMyMutex(this);
			
			LOG_DEBUG("I am the worker on duty this moment . %d !!! \r\n",syscall(SYS_gettid));
			
			if (m_pCFrame->GetWorkHandler() == -1)
			{
				sleep(1);
				continue;
			}
			
			wait_res = epoll_wait(m_pCFrame->GetWorkHandler(),m_stEventList,MAX_EPOLL_FID,MAX_EPOLL_INTV);
			
			LOG_DEBUG("# ---  wait_res = %d errno = %d %s !!! \r\n",wait_res,errno,strerror(errno));
			
			if((wait_res == -1))
			{
				if (errno = EINTR)  
				{
					continue;
				}
				else
				{
					LOG_ERROR("%d:%s\r\n",errno,strerror(errno)); 
					m_iState =  THREAD_STOP;
					break;
				}
			}

			if(wait_res == 0)
			{
				LOG_DEBUG("No sdf valid for watch. %d !!! \r\n",syscall(SYS_gettid));
				sleep(2);
			}
			
			//取第一个处理，并将接口从epoll中删除
			sock = -1;
			if(wait_res > 0)
			{
				LOG_DEBUG("evt is %u,IN=%u,OUT=%u,RDHUP=%u,PRI=%u,ERR=u,HUP=%u,ET=%u,ONESHOT=%u\r\n",
					m_stEventList[0].events,
					EPOLLIN,EPOLLOUT,EPOLLRDHUP,EPOLLPRI,EPOLLERR,EPOLLHUP,EPOLLET,EPOLLONESHOT);
				
				if (m_stEventList[0].events & EPOLLIN)
				{
					sock = (m_stEventList[0].data.fd);	
					
				}
				else if (m_stEventList[0].events &  (EPOLLHUP | EPOLLERR))
				{
					LOG_ERROR("%d:%s\r\n",errno,strerror(errno)); 
					close(m_stEventList[0].data.fd);
					
				}
				epoll_ctl(m_pCFrame->GetWorkHandler(), EPOLL_CTL_DEL, sock, NULL);
			}
		}
		
		// 在收取报文的时候，允许其他线程处理来自其他客户的消息
		if (sock != -1)
		{
			int iRet = WaitAndRecvData(sock);
			// 将接口加入
			if(iRet == 0)
			{
				struct epoll_event ep_evt ;

				ep_evt.events = EPOLLIN; // 必须加上这个否则UDP不顶用 
				ep_evt.data.fd = sock;
				epoll_ctl(m_pCFrame->GetWorkHandler(), EPOLL_CTL_ADD, sock, &ep_evt);
			}
			else if(iRet <0)
			{
				close(sock);
			}
			else
			{
				//不需要我做什么了，都在waitandrecvdata中搞定了
				;
			}
			
		}
	}
}
//##ModelId=51F60CE60230
int CWorker::WaitAndRecvData(int sfd)
{
	unsigned char *buf = m_szBuf;

	// 读取开始符
	int nread = read(sfd, buf, 2 );
	
	if(nread != 2)
	{
		LOG_ERROR("Get First 2 Byte Error ");
		return -1;
	}
	
	//校验头部
	uint16_t * t_prefix = (uint16_t*)buf;
	if(*t_prefix!= PREFIX)	// GT02A协议
	{
		LOG_ERROR("Protocol not support.BEGIN");
		return -2;
	}
	
	//读取长度
	nread = read(sfd, buf+2, 1 );
	
	if(nread != 1)
	{
		LOG_ERROR("Get  1 Byte length Error ");
		return -3;
	}
	//读取内容和结束符
	nread = read(sfd, buf+2+1, buf[2]+2 );
	
	if(nread != buf[2]+2)
	{
		LOG_ERROR("Get  content Error ");
		return -4;
	}
	
	//校验尾部
	uint16_t * t_postfix = (uint16_t*)(buf+2+1+buf[2]);
	if(*t_postfix!=POSTFIX)
	{
		LOG_ERROR("Protocol not support. END, %02x%02x,%02x",buf[2+1+buf[2]],buf[2+1+buf[2]+1],buf[2]);
		return -5;
	}
	
	std::string sReq ;
	sReq.append((char*)buf,2+1+buf[2]+2);
	
	LOG_INFO("%s",MyUtility::CBaseEncode::CharStrToHexStr(sReq).c_str());
	
	StGt02TermToSvrHeader * pStGt02TermToSvrHeader = (StGt02TermToSvrHeader *)buf;
	
	switch(pStGt02TermToSvrHeader->m_ubCmd)
	{
	case 0x10: 	// gps data 
	{
		// gps data 不需要回包，在处理这个包的时候，来自此设备的其他报文，可由其他线程处理
			// 将接口加入,不加的话，在这个场景也无所谓,因为肯定能及时处理一个终端的请求
			{
				struct epoll_event ep_evt ;

				ep_evt.events = EPOLLIN; // 必须加上这个否则UDP不顶用 
				ep_evt.data.fd = sfd;
				epoll_ctl(m_pCFrame->GetWorkHandler(), EPOLL_CTL_ADD, sfd, &ep_evt);
			}
		//压入FIFO;
			StGt02TermToSvrMsg *pobjStGt02TermToSvrMsg = (StGt02TermToSvrMsg *)buf;
			std::stringstream ss;
			pobjStGt02TermToSvrMsg->DumpInfo( ss);

			LOG_INFO(ss.str().c_str());

			int iRet = objCLDDGt02.SetData(pobjStGt02TermToSvrMsg,sfd);
			if(0 != iRet)
			{
				LOG_ERROR("error in objCLDDGt02.SetData imei(%s) iRet = %d ",MyUtility::CBaseEncode::Hex(pobjStGt02TermToSvrMsg->m_stHeader.m_ullImei).c_str(),iRet);
			}
			
			//sleep(20);
			return 1;
		
	}break;
	case 0x1a:	// heart beat
	{	//压入FIFO
		StGt02TermToSvrMsg *pobjStGt02TermToSvrMsg = (StGt02TermToSvrMsg *)buf;
			std::stringstream ss;
			pobjStGt02TermToSvrMsg->DumpInfo( ss);

			LOG_INFO(ss.str().c_str());

			objCLDDGt02.SetData(pobjStGt02TermToSvrMsg,sfd);
		//回应
		StGt02SvrToTermResponse objStGt02SvrToTermResponse(0x1a,0x5468);
		if(sizeof(StGt02SvrToTermResponse) != write(sfd,&objStGt02SvrToTermResponse,sizeof(objStGt02SvrToTermResponse)))
		{
			LOG_ERROR("write heart beat response fail on %d",sfd);
			return -6;
		}
	}break;
	case 0x1d:	// exception 
	{
		//压入FIFO
		StGt02TermToSvrMsg *pobjStGt02TermToSvrMsg = (StGt02TermToSvrMsg *)buf;
			std::stringstream ss;
			pobjStGt02TermToSvrMsg->DumpInfo( ss);

			LOG_INFO(ss.str().c_str());

			objCLDDGt02.SetData(pobjStGt02TermToSvrMsg,sfd);
		//回应
		StGt02SvrToTermResponse objStGt02SvrToTermResponse(0x1d);;
		if(sizeof(StGt02SvrToTermResponse) != write(sfd,&objStGt02SvrToTermResponse,sizeof(objStGt02SvrToTermResponse)))
		{
			LOG_ERROR("write exception response fail on %d",sfd);
			return -7;
		}
	}break;
	case 0x1b:	// ip demand
	case 0x1c:	// response for svr request
	default:
		LOG_INFO("Not support cmd %02x on %d",pStGt02TermToSvrHeader->m_ubCmd,sfd);
	}
	

	return 0;
}

//##ModelId=51F60D940158
int CWorker::Process(const std::string &sInput, std::string &sOutput)
{
	return 0;
}


//##ModelId=51F615FF0289
CWorker::~CWorker()
{
}

//##ModelId=51F618A302EB
CWorker::CWorker(CFrame *pCFrame)
{
	m_pCFrame = pCFrame;
}

