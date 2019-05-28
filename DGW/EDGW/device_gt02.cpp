#include "gvar_edgw.h"



#include "device_gt02_0x10.cpp"

#include "device_gt02_0x17.cpp"

void InitCommandLine()
{
	MyUtility::g_objCCommandLineInfo.AddEntry("ip","--ip=","127.0.0.1",false,false,"EDGW ip ");
	MyUtility::g_objCCommandLineInfo.AddEntry("port","--port=","7788",false,false,"EDGW port");
	
	MyUtility::g_objCCommandLineInfo.AddEntry("imei","--imei=","123456789012345",false,false,"device imei which tag device unique");
	
	
	MyUtility::g_objCCommandLineInfo.AddEntry("count","--count=","1",false,false,"cmd be executed times ");
	MyUtility::g_objCCommandLineInfo.AddEntry("intv","--intv=","10",false,false,"gps data intval  ");
		
	MyUtility::g_objCCommandLineInfo.AddEntry("cmd","--cmd=","free",false,false,
		"\t\tgps	0x10 gps data report \r\n"
		"\t\thb  	0x1a heart beat data report \r\n"
		"\t\texp	0x1d exception date report \r\n"
		"\t\tip		0x00 ip allocate request \r\n"
		"\t\taddr	0x1b address explain request \r\n"
		"\t\tresp	0x1c svr cmd response \r\n"
		"\t\tfree	free combine cmd as a real gt02 \r\n"
		);
}

int ConnectEDGW()
{
	struct addrinfo hints;
	struct addrinfo *result, *rp;
	int sfd = -1 , s, j;
	size_t len;
	ssize_t nread;

	/* Obtain address(es) matching host/port */

	memset(&hints, 0, sizeof(struct addrinfo));
	hints.ai_family = AF_UNSPEC;    /* Allow IPv4 or IPv6 */
	hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
	hints.ai_flags = 0;
	hints.ai_protocol = 0;          /* Any protocol */

	s = getaddrinfo(MyUtility::g_objCCommandLineInfo.GetArgVal("ip").c_str(), 
		MyUtility::g_objCCommandLineInfo.GetArgVal("port").c_str(), 
		&hints, &result);
		
	if (s != 0) 
	{
		fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(s));
		return -1;
	}

	/* getaddrinfo() returns a list of address structures.
	 *               Try each address until we successfully connect(2).
	 *               If socket(2) (or connect(2)) fails, we (close the socket
	 *               and) try the next address. 
	 */

	for (rp = result; rp != NULL; rp = rp->ai_next) 
	{
		sfd = socket(rp->ai_family, rp->ai_socktype,
		rp->ai_protocol);
		if (sfd == -1)
			continue;

		if (connect(sfd, rp->ai_addr, rp->ai_addrlen) != -1)
			break;                  /* Success */

		close(sfd);
	}



	if (rp == NULL) 
	{               /* No address succeeded */
		fprintf(stderr, "Could not connect\n");
		return -1;
	}

	freeaddrinfo(result);           /* No longer needed */
	
	return sfd;
}

void Free()
{
	int sock = -1;
	if((sock=ConnectEDGW()) <= 0)
	{
		std::cout << "* Error in connecting EDGW " 
			<<MyUtility::g_objCCommandLineInfo.GetArgVal("ip")
			<<":"
			<<MyUtility::g_objCCommandLineInfo.GetArgVal("port")
			<<"\r\n";
		return ;
	}
	// send gps per 10 second
	CUMSPThread *pThreadGps = new CDeviceSt02CMD0x10(sock,MyUtility::g_objCCommandLineInfo.GetArgVal("imei"),atoi(MyUtility::g_objCCommandLineInfo.GetArgVal("intv").c_str()));

	pThreadGps->StartWork();

	//0x17
	CUMSPThread *pThreadRecv = new CDeviceSt02CMD0x17(sock,MyUtility::g_objCCommandLineInfo.GetArgVal("imei"),atoi(MyUtility::g_objCCommandLineInfo.GetArgVal("intv").c_str()));

	pThreadRecv->StartWork();
	
	// send hb per 180 second
	
	
	// send exp per 300 second
	
	// send ip once untill succeed
	
	// send addr per 60 second
	
	// send resp when accept svr cmd

	// check status
	while(1)
	{
		sleep(10);
	}
}


int main(int argc, const char *argv[])
{
	InitCommandLine();

	if(argc == 1)
	{
		std::cout << MyUtility::g_objCCommandLineInfo.GetPrompt();
		return 0;
	}	
	MyUtility::g_objCCommandLineInfo.Parse( argc, argv);

	if(MyUtility::g_objCCommandLineInfo.GetArgVal("cmd") == "free")
	{
		Free();
	}
	else 
	{
		std::cout << "Not support cmd : " << MyUtility::g_objCCommandLineInfo.GetArgVal("cmd") << std::endl;
		
	}
	return 0;


  
}


