#include "CListener.h"
#include "CFrame.h"

void CListener::Run()
{
	// 1. 监听
	const MyConfig::CVariableVector & t_objCVariableVector = g_CConfigEntry.GetService("LISTENER").GetVarVectorObj("tcp");
	
	for(int i =0;i<t_objCVariableVector.size();i++)
		Create(t_objCVariableVector.at(i).GetValue().c_str());
	
	// 2. 接受连接
	WaitClient();
	
	
}
//##ModelId=51F6172D01B0
int CListener::Create(const char * service)
{
	//const char * service = g_CConfigEntry.GetService("LISTENER").GetVarVal("tcp").c_str();
	
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	int sfd=-1,s;

	if (g_CConfigEntry.GetService("LISTENER").GetVarVal("tcp") == "") 
	{
		LOG_ERROR("Must point the port : %s ",service);
		return -1;
	}

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
	hints.ai_flags = AI_PASSIVE;    /* For wildcard IP address */
	hints.ai_protocol = 0;          /* Any protocol */
	hints.ai_canonname = NULL;
	hints.ai_addr = NULL;
	hints.ai_next = NULL;

	s = getaddrinfo(NULL, service, &hints, &result);
	if (s != 0) 
	{
		LOG_ERROR("getaddrinfo: %d %s\n", errno,strerror(errno));
		return -2;
	}

	/* getaddrinfo() returns a list of address structures.
	*               Try each address until we successfully bind(2).
	*                             If socket(2) (or bind(2)) fails, we (close the socket
	*                                           and) try the next address. */
	int optval = 1;

	for (rp = result; rp != NULL; rp = rp->ai_next) 
	{
		sfd = socket(rp->ai_family, rp->ai_socktype,rp->ai_protocol);
		
		if (sfd == -1)
		{
		   continue;
		}
		
		if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval,sizeof(optval)) == -1) 
		{
			close(sfd);
			freeaddrinfo(result);
			
			LOG_ERROR("error in setsockopt : %d,%s\n", errno,strerror(errno));
			return -1;
		}

		if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
		{
		   break;                  /* Success */
		}
		else
		{
			LOG_INFO("error in bind : %d,%s\n", errno,strerror(errno));
		}
		close(sfd);
	}

	if (rp == NULL) 
	{               /* No address succeeded */
		LOG_ERROR("Could not bind on %s: %d,%s\n",service, errno,strerror(errno));
		return -1;
	}

	int backlog = MAX_BACK_LOG;

	if (listen(sfd, backlog) == -1) 
	{
		freeaddrinfo(result);
		close(sfd);
		
		LOG_ERROR("Listen error : %d,%s\n",service, errno,strerror(errno));
		return -1;
	}

	freeaddrinfo(result);           /* No longer needed */

	// set non block 
	int flags;

	if((flags = fcntl(sfd, F_GETFL, 0)) < 0)
	{
		LOG_ERROR("fcntl F_GETFL : %d,%s\n",service, errno,strerror(errno));
		return -1;
	}

	if(fcntl(sfd, F_SETFL, flags | O_NONBLOCK) < 0)
	{
		LOG_ERROR("fcntl F_SETFL : %d,%s\n",service, errno,strerror(errno));
		return -1;
	}
	
	int &ep_hdl = m_pCFrame->GetListenHandler();
	
	if (ep_hdl == -1) 
	{
		ep_hdl = epoll_create(MAX_EPOLL_FID);
	}

	struct epoll_event ep_evt ;

	ep_evt.events = EPOLLIN; // 必须加上这个否则UDP不顶用 
	ep_evt.data.fd = sfd;


	if (0 != epoll_ctl(ep_hdl, EPOLL_CTL_ADD, sfd, &ep_evt) )
	{
		LOG_ERROR("epoll_ctl(ep_hdl, EPOLL_CTL_ADD, sdf, &ep_evt) : %d,%s\n",service, errno,strerror(errno));
		return -1;;
	}

	return sfd;
}

//##ModelId=51F617B50377
int CListener::WaitClient()
{
	int wait_res = 0;
	while(m_pCFrame->GetRunState() == 0)
	{
		wait_res = epoll_wait(m_pCFrame->GetListenHandler(),m_stEventList,MAX_EPOLL_FID,MAX_EPOLL_INTV);

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
				m_iRunState =  1;
				break;
			}
		}
				
		for(int j=0;j < wait_res; j++)
		{
			LOG_DEBUG("evt is %u,IN=%u,OUT=%u,RDHUP=%u,PRI=%u,ERR=u,HUP=%u,ET=%u,ONESHOT=%u\r\n",
				m_stEventList[j].events,
				EPOLLIN,EPOLLOUT,EPOLLRDHUP,EPOLLPRI,EPOLLERR,EPOLLHUP,EPOLLET,EPOLLONESHOT);

			if (m_stEventList[j].events & EPOLLIN)
			{
				Process(m_stEventList[j].data.fd);		
			}
			else if (m_stEventList[j].events &  (EPOLLHUP | EPOLLERR))
			{
				LOG_ERROR("%d:%s\r\n",errno,strerror(errno)); 
				close(m_stEventList[j].data.fd);
				m_iRunState =  1;
				break;
			}
		}		

		
	}
}

//##ModelId=51F6184A03A8
int CListener::Process(int listensock)
{
	int len = sizeof(struct sockaddr);
	struct sockaddr_in netclient;
	int retval;

	while (((retval = accept(listensock, (struct sockaddr *)(&netclient), (socklen_t*)&len)) == -1) && (errno == EINTR)) ;  

	// 获取对端信息
	if(retval != -1)
	{	
		char buf[8192];
		int h_error;
		struct hostent *hp;
		struct hostent result;

		/*
 *        int gethostbyaddr_r(const void *addr, socklen_t len, int type,
 *                       struct hostent *ret, char *buf, size_t buflen,
 *                                      struct hostent **result, int *h_errnop);*/

		gethostbyaddr_r((char *)&(netclient.sin_addr), 4, AF_INET, &result,buf, 8192,&hp, &h_error);

		if (hp == NULL)
			strncpy(buf, inet_ntoa(netclient.sin_addr), 8191);
		else
			strncpy(buf, hp->h_name, 8191);

		buf[8192] = 0;

		LOG_DEBUG("a new client in ,remote address is %s \r\n",buf);

		//epoll on it 
		
		int &ep_hdl = m_pCFrame->GetWorkHandler();
	
		if (ep_hdl == -1) 
		{
			ep_hdl = epoll_create(MAX_EPOLL_FID);
		}

		struct epoll_event ep_evt ;

		ep_evt.events = EPOLLIN; // 必须加上这个否则UDP不顶用 
		ep_evt.data.fd = retval;


		if (0 != epoll_ctl(ep_hdl, EPOLL_CTL_ADD, retval, &ep_evt) )
		{
			LOG_ERROR("epoll_ctl(ep_hdl, EPOLL_CTL_ADD, sock, &ep_evt) : %d,%s\n", errno,strerror(errno));
			return -1;;
		}



		//设置长连接属性
		int keepAlive = 1;
		int keepIdle = 1000;
		int keepInterval = 10;
		int keepCount = 3;
		int cfd = retval;

		if(setsockopt(cfd, SOL_SOCKET, SO_KEEPALIVE, (void*)&keepAlive, sizeof(keepAlive)) == -1)
		{
			LOG_INFO("setsockopt(cfd, SOL_SOCKET, SO_KEEPALIVE, (void*)&keepAlive, sizeof(keepAlive)): %d,%s\n", errno,strerror(errno));
			
		}
/*
		if(setsockopt(cfd, SOL_TCP, TCP_KEEPIDLE, (void *)&keepIdle, sizeof(keepIdle)) == -1)
		{
			return -1;
		}

		if(setsockopt(cfd, SOL_TCP, TCP_KEEPINTVL, (void *)&keepInterval, sizeof(keepInterval)) == -1)
		{
			return -1;
		}

		if(setsockopt(cfd, SOL_TCP, TCP_KEEPCNT, (void *)&keepCount, sizeof(keepCount)) == -1)
		{
			return -1;
		}
*/
		//non block
		int flags;
		int socket = retval;

		if((flags = fcntl(socket, F_GETFL, 0)) < 0)
		{
			LOG_INFO("fcntl(socket,FGETFL,0):%d, %s",errno,strerror(errno));
		}

		if(fcntl(socket, F_SETFL, flags | O_NONBLOCK) < 0)
		{
			LOG_INFO("fcntl(socket, F_SETFL, flags | O_NONBLOCK):%d, %s",errno,strerror(errno));
		}	
	}

	return retval;
}

//##ModelId=51F6186101DE
CListener::CListener()
{
	m_pCFrame = NULL;
	m_iRunState =  1;
}


//##ModelId=51F6186101EE
CListener::~CListener()
{
}

//##ModelId=51F6191C0025
CListener::CListener(CFrame *pCFrame)
{
	m_pCFrame = pCFrame;
	m_iRunState = 0;
}


