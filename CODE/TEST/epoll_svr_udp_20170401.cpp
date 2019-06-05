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

#define BUF_SIZE 500

int create_epoll_svr_udp_socket(const char * service)
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
	hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
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

	for (rp = result; rp != NULL; rp = rp->ai_next) {
		sfd = socket(rp->ai_family, rp->ai_socktype,
		       rp->ai_protocol);
		if (sfd == -1)
		   continue;

		if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0)
		   break;                  /* Success */
		close(sfd);
	}

	if (rp == NULL) {               /* No address succeeded */
		fprintf(stderr, "Could not bind\n");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(result);           /* No longer needed */

	return sfd;

	

}

int create_epoll_on_socket(int sock)
{
	int ep_hdl = -1;

	ep_hdl = epoll_create(500000);

	struct epoll_event ep_evt ;

	ep_evt.events = EPOLLIN; // 必须加上这个否则UDP不顶用 
	ep_evt.data.fd = sock;


	epoll_ctl(ep_hdl, EPOLL_CTL_ADD, sock, &ep_evt) ;

	return ep_hdl;
	
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

		printf("\n*****\nReceived %ld bytes data:%s\n", (long) nread,  buf);

		if (write(sfd, buf, nread ) != nread)
			fprintf(stderr, "Error sending response\n");
	}
	else
		close(sfd);

	return 0;
}
int read_response_udp_sock(int sfd)
{
	struct sockaddr_storage peer_addr;
	socklen_t peer_addr_len;
	ssize_t nread;
	char buf[BUF_SIZE];
	int s;

        peer_addr_len = sizeof(struct sockaddr_storage);

        nread = recvfrom(sfd, buf, BUF_SIZE, 0,
	       (struct sockaddr *) &peer_addr, &peer_addr_len);

       if (nread == -1)
	   return -1;               /* Ignore failed request */

       char host[NI_MAXHOST], service[NI_MAXSERV];

       s = getnameinfo((struct sockaddr *) &peer_addr,
		       peer_addr_len, host, NI_MAXHOST,
		       service, NI_MAXSERV, NI_NUMERICSERV);
      if (s == 0)
	   printf("\n******\nReceived %ld bytes from %s:%s data:%s\n",
		   (long) nread, host, service, buf);
       else
	   fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));

       if (sendto(sfd, buf, nread, 0,
		   (struct sockaddr *) &peer_addr,
		   peer_addr_len) != nread)
	   fprintf(stderr, "Error sending response\n");

	return 0;
}

int main(int argc,char ** argv)
{
	printf("\r\n");

	// 1. create socket
	int sock_udp = create_epoll_svr_udp_socket(argv[1]);


	// 2. epoll on socket
	int ep_res = create_epoll_on_socket(sock_udp);

	// 3. read and response 
	struct epoll_event evt_list[500000];
	int wait_res = -1;

	while(1)
	{
		wait_res = epoll_wait(ep_res,evt_list,500000,2000);
		
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
			if (evt_list[j].events & EPOLLIN)
				read_response_udp_sock(evt_list[j].data.fd);		
			else if (evt_list[j].events &  (EPOLLHUP | EPOLLERR))
			{
				printf("%d:%s\r\n",errno,strerror(errno)); exit(errno);
			}
		}		

		
	}	

	return -1;

}
