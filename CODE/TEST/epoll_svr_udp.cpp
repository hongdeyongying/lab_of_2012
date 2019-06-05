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
#include <sys/socket.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>
#define BUF_SIZE 500

// for p2p test
#include "./proto.h"
#include "./Exception.h"

UserList ClientList;

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

		printf("Received %ld bytes data:%s\n", (long) nread,  buf);

		if (write(sfd, buf, nread ) != nread)
			fprintf(stderr, "Error sending response\n");
	}
	else
		close(sfd);

	return 0;
}
stUserListNode GetUser(char *username)
{
	for(UserList::iterator UserIterator=ClientList.begin();
						UserIterator!=ClientList.end();
							++UserIterator)
	{
		if( strcmp( ((*UserIterator)->userName), username) == 0 )
			return *(*UserIterator);
	}
	//throw Exception("not find this user");
}
int read_response_udp_sock(int sfd)
{
	struct sockaddr_storage peer_addr;
	socklen_t peer_addr_len;
	ssize_t nread;
	char buf[BUF_SIZE];
	
	stMessage (*recvbuf) = (stMessage * )buf;
	
	memset(buf,0,BUF_SIZE);
	
	int s;

        peer_addr_len = sizeof(struct sockaddr_storage);

        nread = recvfrom(sfd, buf, BUF_SIZE, 0,
	       (struct sockaddr *) &peer_addr, &peer_addr_len);

	sockaddr_in *peer_addr_in = (sockaddr_in *)&peer_addr;


       if (nread == -1)
	   return -1;               /* Ignore failed request */

       char host[NI_MAXHOST], service[NI_MAXSERV];

       s = getnameinfo((struct sockaddr *) &peer_addr,
		       peer_addr_len, host, NI_MAXHOST,
		       service, NI_MAXSERV, NI_NUMERICSERV);
      if (s == 0)
	   printf("Received %ld bytes from %s:%s data:%s\n",
		   (long) nread, host, service, buf);
       else
	   fprintf(stderr, "getnameinfo: %s\n", gai_strerror(s));
   
		// if p2p collaberator
		
		if(recvbuf->iMessageType < 5 && recvbuf->iMessageType > 0)
		{
			int messageType = recvbuf->iMessageType;
			switch(messageType){
			case LOGIN:
				{
					//  将这个用户的信息记录到用户列表中
					printf("has a user login : %s\n", (*recvbuf).message.loginmember.userName);
					stUserListNode *currentuser = new stUserListNode();
					strncpy(currentuser->userName, (*recvbuf).message.loginmember.userName,sizeof(currentuser->userName));
					currentuser->ip = ntohl(peer_addr_in->sin_addr.s_addr);
					currentuser->port = ntohs(peer_addr_in->sin_port);
					
					ClientList.push_back(currentuser);

					// 发送已经登陆的客户信息
					int nodecount = (int)ClientList.size();
					sendto(sfd, (const char*)&nodecount, sizeof(int), 0, (const sockaddr*)&peer_addr, peer_addr_len);
					for(UserList::iterator UserIterator=ClientList.begin();
							UserIterator!=ClientList.end();
							++UserIterator)
					{
						sendto(sfd, (const char*)(*UserIterator), sizeof(stUserListNode), 0, (const sockaddr*)&peer_addr, peer_addr_len); 
					}

					break;
				};
				case LOGOUT:
					{
						// 将此客户信息删除
						printf("has a user logout : %s\n", (*recvbuf).message.logoutmember.userName);
						UserList::iterator removeiterator = ClientList.end();
						for(UserList::iterator UserIterator=ClientList.begin();
							UserIterator!=ClientList.end();
							++UserIterator)
						{
							if( strcmp( ((*UserIterator)->userName), (*recvbuf).message.logoutmember.userName) == 0 )
							{
								removeiterator = UserIterator;
								break;
							}
						}
						if(removeiterator != ClientList.end())
							ClientList.remove(*removeiterator);
						break;
					}
				case P2PTRANS:
					{
						// 某个客户希望服务端向另外一个客户发送一个打洞消息
						printf("%s wants to p2p %s\n",inet_ntoa(peer_addr_in->sin_addr),(*recvbuf).message.translatemessage.userName);
						stUserListNode node = GetUser((*recvbuf).message.translatemessage.userName);
						sockaddr_in remote;
						remote.sin_family=AF_INET;
						remote.sin_port= htons(node.port); 
						remote.sin_addr.s_addr = htonl(node.ip);

						in_addr tmp;
						tmp.s_addr = htonl(node.ip);
						printf("the address is %s,and port is %d\n",inet_ntoa(tmp), node.port);

						stP2PMessage transMessage;
						transMessage.iMessageType = P2PSOMEONEWANTTOCALLYOU;
						transMessage.iStringLen = ntohl(peer_addr_in->sin_addr.s_addr);
						transMessage.Port = ntohs(peer_addr_in->sin_port);
                        
						sendto(sfd,(const char*)&transMessage, sizeof(transMessage), 0, (const sockaddr *)&remote, sizeof(remote));

						break;
					}
				
				case GETALLUSER:
					{
						int command = GETALLUSER;
						sendto(sfd, (const char*)&command, sizeof(int), 0, (const sockaddr*)&peer_addr, peer_addr_len);

						int nodecount = (int)ClientList.size();
						sendto(sfd, (const char*)&nodecount, sizeof(int), 0, (const sockaddr*)&peer_addr, peer_addr_len);

						for(UserList::iterator UserIterator=ClientList.begin();
								UserIterator!=ClientList.end();
								++UserIterator)
						{
							sendto(sfd, (const char*)(*UserIterator), sizeof(stUserListNode), 0, (const sockaddr*)&peer_addr, peer_addr_len); 
						}
						break;
					}
			}
		}                    
		else 
		{
			if (sendto(sfd, buf, nread, 0, (struct sockaddr *) &peer_addr, peer_addr_len) != nread)
				fprintf(stderr, "Error sending response\n");
		}

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

