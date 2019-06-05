#include <stdio.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <sys/epoll.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/socket.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>

#define BUF_SIZE 500

int create_epoll_svr_tcp_socket(const char * service)
{
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	int sfd=-1,s;

	if (service == NULL) {
		fprintf(stderr, "you must point the PORT \n", service);
		exit(EXIT_FAILURE);
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
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit(EXIT_FAILURE);
	}

	/* getaddrinfo() returns a list of address structures.
	*               Try each address until we successfully bind(2).
	*                             If socket(2) (or bind(2)) fails, we (close the socket
	*                                           and) try the next address. */
	int optval = 1;

	for (rp = result; rp != NULL; rp = rp->ai_next) {
		sfd = socket(rp->ai_family, rp->ai_socktype,
		       rp->ai_protocol);
		if (sfd == -1)
		   continue;

		if (setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &optval,
                    sizeof(optval)) == -1) {
			close(sfd);
			freeaddrinfo(result);
			return -1;
		    }

		if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
		   break;                  /* Success */
		close(sfd);
	}

	if (rp == NULL) {               /* No address succeeded */
		fprintf(stderr, "Could not bind\n");
		exit(EXIT_FAILURE);
	}

	int backlog = 10000;

	if (listen(sfd, backlog) == -1) {
		freeaddrinfo(result);
		close(sfd);
		return -1;
	}

	freeaddrinfo(result);           /* No longer needed */

	// set non block 
	int flags;

	if((flags = fcntl(sfd, F_GETFL, 0)) < 0)
	{
		return -1;
	}

	if(fcntl(sfd, F_SETFL, flags | O_NONBLOCK) < 0)
	{
		return -1;
	}

	return sfd;

	

}

int create_epoll_on_socket(int sock)
{
	static int ep_hdl = -1;

	
	if (ep_hdl == -1) 
		ep_hdl = epoll_create(500000);

	struct epoll_event ep_evt ;

	ep_evt.events = EPOLLIN; // 必须加上这个否则UDP不顶用 
	ep_evt.data.fd = sock;


	epoll_ctl(ep_hdl, EPOLL_CTL_ADD, sock, &ep_evt) ;

	return ep_hdl;
	
}

int accept_new_tcp_connection(int listensock)
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

		printf("remote address is %s \r\n",buf);

		//epoll on it 
		create_epoll_on_socket(retval);


		//设置长连接属性
		int keepAlive = 1;
		int keepIdle = 1000;
		int keepInterval = 10;
		int keepCount = 3;
		int cfd = retval;

		if(setsockopt(cfd, SOL_SOCKET, SO_KEEPALIVE, (void*)&keepAlive, sizeof(keepAlive)) == -1)
		{
			return -1;
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
			return -1;
		}

		if(fcntl(socket, F_SETFL, flags | O_NONBLOCK) < 0)
		{
			return -1;
		}	
		

	}

	return retval;	
}

int read_response_tcp_sock(int sfd)
{
	char buf[BUF_SIZE];

	int nread = read(sfd, buf, BUF_SIZE );

	if (nread == -1)
	{
		printf("error in read from %d\r\n",sfd);
		return -1;               /* Ignore failed request */

	}

	if (nread >0)
	{

		printf("Received %ld bytes data:%s\n", (long) nread,  buf);

		if (write(sfd, buf, nread ) != nread)
			fprintf(stderr, "Error sending response\n");
	}
	else
		close(sfd);

	return 0;
}

int main(int argc,char ** argv)
{
	printf("\r\n");

	// 1. create socket
	int sock_tcp = create_epoll_svr_tcp_socket(argv[1]);


	// 2. epoll on socket
	int ep_res = create_epoll_on_socket(sock_tcp);

	// 3. read and response 
	struct epoll_event evt_list[500000];
	int wait_res = -1;

	while(1)
	{
		wait_res = epoll_wait(ep_res,evt_list,500000,2000);

		printf("# ---  wait_res = %d errno = %d %s !!! \r\n",wait_res,errno,strerror(errno));
		
		if((wait_res == -1))
		{
			if (errno = EINTR)  
			{
				continue;
			}
			else
			{
				printf("%d:%s\r\n",errno,strerror(errno)); exit(errno);
			}
		}
		
		for(int j=0;j < wait_res; j++)
		{
			printf("evt is %u,IN=%u,OUT=%u,RDHUP=%u,PRI=%u,ERR=u,HUP=%u,ET=%u,ONESHOT=%u\r\n",
				evt_list[j].events,EPOLLIN,EPOLLOUT,EPOLLRDHUP,EPOLLPRI,EPOLLERR,EPOLLHUP,EPOLLET,EPOLLONESHOT);

			if (evt_list[j].events & EPOLLIN)
			{
				if(evt_list[j].data.fd == sock_tcp)
					accept_new_tcp_connection(sock_tcp);
				else
					read_response_tcp_sock(evt_list[j].data.fd);		
			}
			else if (evt_list[j].events &  (EPOLLHUP | EPOLLERR))
			{
				printf("%d:%s\r\n",errno,strerror(errno)); exit(errno);
			}
		}		

		
	}	

	return -1;

}

