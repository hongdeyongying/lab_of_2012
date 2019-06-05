#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


#include <sys/socket.h>
       #include <netinet/in.h>
       #include <arpa/inet.h>


#include <unistd.h>
#include <string.h>

#define BUF_SIZE 500

// for p2p test
#include "./proto.h"
#include "./Exception.h"
#include <iostream>
using namespace std;

UserList ClientList;

#define COMMANDMAXC 256
#define MAXRETRY    5

int PrimaryUDP;
char UserName[10];
char ServerIP[20];
char ServerPort[8];

bool RecvedACK;

enum ENUM_THREAD_ATTRIBUTES
{
        CONTENTION_SCOPE        =       0X01,
        DETACH_STATE            =       0X02,
        STACK_ADDR                      =       0X04,
        STACK_SIZE                      =       0X08,
        SCHED_PARAM                     =       0X10,
        SCHED_POLICY            =       0X20,
        INHERITSCHED            =       0X40
};

typedef struct STRU_THREAD_ATTRIBUTES
{
        unsigned char   mask;
        int             contention_scope;
        int             detach_state;
        void    *stack_addr;
        size_t  stack_size;
        struct sched_param      *param;
        int             policy;
        int             inheritsched;
}THREAD_ATTR;

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

void BindSock(int sock)
{
	sockaddr_in sin;
	sin.sin_addr.s_addr = INADDR_ANY;
	sin.sin_family = AF_INET;
	sin.sin_port = 0;
	
	if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0)
	{
		cout << "bind error :" << errno <<" " << strerror(errno) << " :" << sock<< endl; 
		return ;//throw Exception("bind error");
	}
	
	/*
           struct sockaddr_un my_addr;
		   
           memset(&my_addr, 0, sizeof(struct sockaddr_un));
                               //* Clear structure /
           my_addr.sun_family = AF_UNIX;
           strncpy(my_addr.sun_path, MY_SOCK_PATH,sizeof(my_addr.sun_path) - 1);

           if (bind(sock, (struct sockaddr *) &my_addr,sizeof(struct sockaddr_un)) == -1)
               handle_error("bind");
	
	*/
}

void ConnectToServer(int sock,char *username, char *serverip)
{
	sockaddr_in remote;
	remote.sin_addr.s_addr = inet_addr(serverip);
	remote.sin_family = AF_INET;
	remote.sin_port = htons(atoi(ServerPort));
	
	stMessage sendbuf;
	sendbuf.iMessageType = LOGIN;
	strncpy(sendbuf.message.loginmember.userName, username, 10);

	sendto(sock, (const char*)&sendbuf, sizeof(sendbuf), 0, (const sockaddr*)&remote,sizeof(remote));

	int usercount;
	socklen_t fromlen = sizeof(remote);
	int iread = recvfrom(sock, (char *)&usercount, sizeof(int), 0, (sockaddr *)&remote, &fromlen);
	if(iread<=0)
	{
		cout << "Login error\n" ;
		return ;// throw Exception("Login error\n");
	}

	// 登录到服务端后，接收服务端发来的已经登录的用户的信息
	cout<<"Have "<<usercount<<" users logined server:"<<endl;
	for(int i = 0;i<usercount;i++)
	{
		stUserListNode *node = new stUserListNode;
		recvfrom(sock, (char*)node, sizeof(stUserListNode), 0, (sockaddr *)&remote, &fromlen);
		ClientList.push_back(node);
		cout<<"Username:"<<node->userName<<endl;
		in_addr tmp;
		tmp.s_addr = htonl(node->ip);
		cout<<"UserIP:"<<inet_ntoa(tmp)<<endl;
		cout<<"UserPort:"<<node->port<<endl;
		cout<<""<<endl;
	}
}

void OutputUsage()
{
	cout<<"You can input you command:\n"
		<<"Command Type:\"send\",\"exit\",\"getu\"\n"
		<<"Example : send Username Message\n"
		<<"          exit\n"
		<<"          getu\n"
		<<endl;
}

/* 这是主要的函数：发送一个消息给某个用户(C)
 *流程：直接向某个用户的外网IP发送消息，如果此前没有联系过
 *      那么此消息将无法发送，发送端等待超时。
 *      超时后，发送端将发送一个请求信息到服务端，
 *      要求服务端发送给客户C一个请求，请求C给本机发送打洞消息
 *      以上流程将重复MAXRETRY次
 */
bool SendMessageTo(char *UserName, char *Message)
{
	char realmessage[256];
	unsigned int UserIP;
	unsigned short UserPort;
	bool FindUser = false;
	for(UserList::iterator UserIterator=ClientList.begin();
						UserIterator!=ClientList.end();
						++UserIterator)
	{
		if( strcmp( ((*UserIterator)->userName), UserName) == 0 )
		{
			UserIP = (*UserIterator)->ip;
			UserPort = (*UserIterator)->port;
			FindUser = true;
		}
	}

	if(!FindUser)
		return false;

	strcpy(realmessage, Message);
	for(int i=0;i<MAXRETRY;i++)
	{
		RecvedACK = false;

		sockaddr_in remote;
		remote.sin_addr.s_addr = htonl(UserIP);
		remote.sin_family = AF_INET;
		remote.sin_port = htons(UserPort);
		stP2PMessage MessageHead;
		MessageHead.iMessageType = P2PMESSAGE;
		MessageHead.iStringLen = (int)strlen(realmessage)+1;
		int isend = sendto(PrimaryUDP, (const char *)&MessageHead, sizeof(MessageHead), 0, (const sockaddr*)&remote, sizeof(remote));
		isend = sendto(PrimaryUDP, (const char *)&realmessage, MessageHead.iStringLen, 0, (const sockaddr*)&remote, sizeof(remote));
		
		// 等待接收线程将此标记修改
		for(int j=0;j<10;j++)
		{
			if(RecvedACK)
				return true;
			else
				usleep(100000);
		}

		// 没有接收到目标主机的回应，认为目标主机的端口映射没有
		// 打开，那么发送请求信息给服务器，要服务器告诉目标主机
		// 打开映射端口（UDP打洞）
		sockaddr_in server;
		server.sin_addr.s_addr = inet_addr(ServerIP);
		server.sin_family = AF_INET;
		server.sin_port = htons(atoi(ServerPort));
	
		stMessage transMessage;
		transMessage.iMessageType = P2PTRANS;
		strcpy(transMessage.message.translatemessage.userName, UserName);

		sendto(PrimaryUDP, (const char*)&transMessage, sizeof(transMessage), 0, (const sockaddr*)&server, sizeof(server));
		usleep(100000);// 等待对方先发送信息。
	}
	return false;
}

// 解析命令，暂时只有exit和send命令
// 新增getu命令，获取当前服务器的所有用户
void ParseCommand(char * CommandLine)
{
	if(strlen(CommandLine)<4)
		return;
	char Command[10];
	strncpy(Command, CommandLine, 4);
	Command[4]='\0';

	if(strcmp(Command,"exit")==0)
	{
		stMessage sendbuf;
		sendbuf.iMessageType = LOGOUT;
		strncpy(sendbuf.message.logoutmember.userName, UserName, 10);
		sockaddr_in server;
		server.sin_addr.s_addr = inet_addr(ServerIP);
		server.sin_family = AF_INET;
		server.sin_port = htons(atoi(ServerPort));

		sendto(PrimaryUDP,(const char*)&sendbuf, sizeof(sendbuf), 0, (const sockaddr *)&server, sizeof(server));
		shutdown(PrimaryUDP, 2);
		close(PrimaryUDP);
		exit(0);
	}
	else if(strcmp(Command,"send")==0)
	{
		char sendname[20];
		char message[COMMANDMAXC];
		int i;
		for(i=5;;i++)
		{
			if(CommandLine[i]!=' ')
				sendname[i-5]=CommandLine[i];
			else
			{
				sendname[i-5]='\0';
				break;
			}
		}
		strcpy(message, &(CommandLine[i+1]));
		if(SendMessageTo(sendname, message))
			printf("Send OK!\n");
		else 
			printf("Send Failure!\n");
	}
	else if(strcmp(Command,"getu")==0)
	{
		int command = GETALLUSER;
		sockaddr_in server;
		server.sin_addr.s_addr = inet_addr(ServerIP);
		server.sin_family = AF_INET;
		server.sin_port = htons(atoi(ServerPort));

		sendto(PrimaryUDP,(const char*)&command, sizeof(command), 0, (const sockaddr *)&server, sizeof(server));
	}
}

// 接受消息线程
static void * RecvThreadProc(void * lpParameter)
{
	sockaddr_in remote;
	socklen_t sinlen = sizeof(remote);
	stP2PMessage recvbuf;
	for(;;)
	{
		int iread = recvfrom(PrimaryUDP, (char *)&recvbuf, sizeof(recvbuf), 0, (sockaddr *)&remote, &sinlen);
		if(iread<=0)
		{
			printf("recv error\n");
			continue;
		}
		switch(recvbuf.iMessageType)
		{
		case P2PMESSAGE:
			{
				// 接收到P2P的消息
				char *comemessage= new char[recvbuf.iStringLen];
				int iread1 = recvfrom(PrimaryUDP, comemessage, 256, 0, (sockaddr *)&remote, &sinlen);
				comemessage[iread1-1] = '\0';
				if(iread1<=0)
				{
					cout << "Recv Message Error\n";
					return NULL;//throw Exception("Recv Message Error\n");
				}
				else
				{
					printf("Recv a Message:%s\n",comemessage);
					
					stP2PMessage sendbuf;
					sendbuf.iMessageType = P2PMESSAGEACK;
					sendto(PrimaryUDP, (const char*)&sendbuf, sizeof(sendbuf), 0, (const sockaddr*)&remote, sizeof(remote));
				}

				delete []comemessage;
				break;

			}
		case P2PSOMEONEWANTTOCALLYOU:
			{
				
				// 接收到打洞命令，向指定的IP地址打洞
				printf("Recv p2someonewanttocallyou data from ");
				cout << inet_ntoa(remote.sin_addr) << ":" << remote.sin_port << endl;
				
				
				sockaddr_in remote_p2p;
				remote_p2p.sin_addr.s_addr = htonl(recvbuf.iStringLen);
				remote_p2p.sin_family = AF_INET;
				remote_p2p.sin_port = htons(recvbuf.Port);
				
				//
				in_addr tmp;
				tmp.s_addr = htonl(recvbuf.iStringLen);
				cout <<"send P2PTRASH msg to " <<inet_ntoa(tmp) << ":" << recvbuf.Port << endl;

				// UDP hole punching
				stP2PMessage message;
				message.iMessageType = P2PTRASH;
				sendto(PrimaryUDP, (const char *)&message, sizeof(message), 0, (const sockaddr*)&remote_p2p, sizeof(remote_p2p));
                
				break;
			}
		case P2PMESSAGEACK:
			{
				// 发送消息的应答
				RecvedACK = true;
				break;
			}
		case P2PTRASH:
			{
				// 对方发送的打洞消息，忽略掉。
				//do nothing ...
				printf("Recv p2ptrash data from ：");
				cout << inet_ntoa(remote.sin_addr) << ":" << remote.sin_port << endl;
				break;
			}
		case GETALLUSER:
			{
				int usercount;
				socklen_t fromlen = sizeof(remote);
				int iread = recvfrom(PrimaryUDP, (char *)&usercount, sizeof(int), 0, (sockaddr *)&remote, &fromlen);
				if(iread<=0)
				{
					return NULL;//throw Exception("Login error\n");
				}
				
				ClientList.clear();

				cout<<"Have "<<usercount<<" users logined server:"<<endl;
				for(int i = 0;i<usercount;i++)
				{
					stUserListNode *node = new stUserListNode;
					recvfrom(PrimaryUDP, (char*)node, sizeof(stUserListNode), 0, (sockaddr *)&remote, &fromlen);
					ClientList.push_back(node);
					cout<<"Username:"<<node->userName<<endl;
					in_addr tmp;
					tmp.s_addr = htonl(node->ip);
					cout<<"UserIP:"<<inet_ntoa(tmp)<<endl;
					cout<<"UserPort:"<<node->port<<endl;
					cout<<""<<endl;
				}
				break;
			}
		}
	}
}


#include <pthread.h>
#include <signal.h>


int
main(int argc, char *argv[])
{
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	int &sfd = PrimaryUDP, s, j;
	size_t len;
	ssize_t nread;
	char buf[BUF_SIZE];

	cout<<"Please input server ip:";
	cin>>ServerIP;

	cout<<"Please input server port:";
	cin>>ServerPort;

	cout<<"Please input your name:";
	cin>>UserName;
	/* Obtain address(es) matching host/port */

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_DGRAM; /* Datagram socket */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;          /* Any protocol */

	s = getaddrinfo(ServerIP, ServerPort, &hints, &result);
	if (s != 0) {
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		exit(EXIT_FAILURE);
	}

	/* getaddrinfo() returns a list of address structures.
	*               Try each address until we successfully connect(2).
	*                             If socket(2) (or connect(2)) fails, we (close the socket
	*                                           and) try the next address. */

	sfd = socket(AF_INET, SOCK_DGRAM,0);
	/*
	for (rp = result; rp != NULL; rp = rp->ai_next) {
		sfd = socket(rp->ai_family, rp->ai_socktype,rp->ai_protocol);
		
		if (sfd == -1)
		{
			cout << "error on socket " <<endl;
		   continue;
		}

		if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
		{
			cout << "succeeded on socket :"<<sfd <<endl;
		   break;                  ///* Success 
		}

		close(sfd);
	}



	if (rp == NULL) {               ///* No address succeeded 
		fprintf(stderr, "Could not connect\n");
		exit(EXIT_FAILURE);
	}

	freeaddrinfo(result);           //* No longer needed 
//*/
	/* Send remaining command-line arguments as separate
	*               datagrams, and read responses from server */

   	try
	{
		//InitWinSock();
		
		//PrimaryUDP = mksock(SOCK_DGRAM);
		BindSock(PrimaryUDP);


		ConnectToServer(PrimaryUDP, UserName, ServerIP);
		
		
		pthread_t m_hThread;
		
		THREAD_ATTR attr;
        attr.mask = CONTENTION_SCOPE|DETACH_STATE;
        attr.contention_scope = PTHREAD_SCOPE_SYSTEM;
        attr.detach_state = PTHREAD_CREATE_DETACHED;
		
		//pthread_attr_init(&attr);
        
		
		pthread_create(&m_hThread,NULL,RecvThreadProc,NULL);

		//HANDLE threadhandle = CreateThread(NULL, 0, RecvThreadProc, NULL, NULL, NULL);
		//CloseHandle(threadhandle);
		OutputUsage();

		for(;;)
		{
			char Command[COMMANDMAXC];
			gets(Command);
			ParseCommand(Command);
		}
	}
	catch(Exception &e)
	{
		printf(e.GetMessage());
		return 1;
	}
	return 0;

   exit(EXIT_SUCCESS);
}


