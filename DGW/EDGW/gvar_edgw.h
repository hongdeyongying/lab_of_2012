#ifndef GVAR_EDGW_H_20130729
#define GVAR_EDGW_H_20130729
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

#include "CCommandLineInfo.h"
#include "CConfigEntry.h"
#include "Log.h"
#include "UMSPThread.h"
#include <sys/types.h>
#include <sys/syscall.h> // for gettid

#include <unistd.h>
#include <string>
#define BUF_SIZE 1024*11
#include "CBaseEncode.h"

#define CONFIG_FILE_PATH "../cnf/edgw_index.xml"


#define MAX_EPOLL_FID	500000
#define MAX_EPOLL_INTV	2000
#define MAX_BACK_LOG	10000

#ifndef GVAR_EDGW_CPP_20130729
extern MyConfig::CConfigEntry g_CConfigEntry;
#endif

#endif //GVAR_EDGW_H_20130729
