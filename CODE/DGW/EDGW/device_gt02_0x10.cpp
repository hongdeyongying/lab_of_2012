#ifndef DEVICE_GT02_0x10_CPP
#define DEVICE_GT02_0x10_CPP

#include "UMSPThread.h"
#include <string>
#include "gt02.h"


class CDeviceSt02CMD0x10:public CUMSPThread
{
public:
	int m_sock;
	std::string m_imei;
	std::vector<CGt02Position> m_vPosition;
	int m_intval;
	
		
	CDeviceSt02CMD0x10(int sock,const std::string & imei="123456789012345",int intv=10):m_sock(sock),m_imei(imei),m_intval(intv)
	{
		m_iState = THREAD_RUN;
		// init position
		m_vPosition.push_back(CGt02Position(113.903574,22.530215));
		m_vPosition.push_back(CGt02Position(113.907786,22.531232));
		m_vPosition.push_back(CGt02Position(113.908201,22.531319));
		m_vPosition.push_back(CGt02Position(113.910503,22.532823));
		m_vPosition.push_back(CGt02Position(113.912227,22.535473));
		m_vPosition.push_back(CGt02Position(113.915219,22.535681));
		m_vPosition.push_back(CGt02Position(113.920066,22.533541));
		m_vPosition.push_back(CGt02Position(113.9195014,22.5296822));
		m_vPosition.push_back(CGt02Position(113.920779,22.526464));
		m_vPosition.push_back(CGt02Position(113.927308,22.524685));
		m_vPosition.push_back(CGt02Position(113.931856,22.524204));
		m_vPosition.push_back(CGt02Position(113.938844,22.523997));
		m_vPosition.push_back(CGt02Position(113.94437,22.523928));
		m_vPosition.push_back(CGt02Position(113.990674,22.525028));
		m_vPosition.push_back(CGt02Position(113.994845,22.527373));
		m_vPosition.push_back(CGt02Position(114.022926,22.531556));
		m_vPosition.push_back(CGt02Position(114.032622,22.529821));
		m_vPosition.push_back(CGt02Position(114.037789,22.530286));
		m_vPosition.push_back(CGt02Position(114.052173,22.53119));
		m_vPosition.push_back(CGt02Position(114.056433,22.531308));
		m_vPosition.push_back(CGt02Position(114.063974,22.531345));
		m_vPosition.push_back(CGt02Position(114.073777,22.532087));
		m_vPosition.push_back(CGt02Position(114.076178,22.531662));
		m_vPosition.push_back(CGt02Position(114.079837,22.535793));
		m_vPosition.push_back(CGt02Position(114.083989,22.537275));
		m_vPosition.push_back(CGt02Position(114.091406,22.537863));
		m_vPosition.push_back(CGt02Position(114.097139,22.537922));
		m_vPosition.push_back(CGt02Position(114.099715,22.541523));
		m_vPosition.push_back(CGt02Position(114.099665,22.548263));
		m_vPosition.push_back(CGt02Position(114.0995173,22.55567667));
		m_vPosition.push_back(CGt02Position(114.099329,22.562846));
		m_vPosition.push_back(CGt02Position(114.099284,22.566599));
		m_vPosition.push_back(CGt02Position(114.099063,22.573087));
		m_vPosition.push_back(CGt02Position(114.09904,22.576161));
		m_vPosition.push_back(CGt02Position(114.20894,22.689492));
		m_vPosition.push_back(CGt02Position(114.214152,22.694764));
		m_vPosition.push_back(CGt02Position(114.2210116,22.701766));
		m_vPosition.push_back(CGt02Position(114.220696,22.705243));
		m_vPosition.push_back(CGt02Position(114.215247,22.707804));
		m_vPosition.push_back(CGt02Position(114.213669,22.713332));
		m_vPosition.push_back(CGt02Position(114.213564,22.719689));
		m_vPosition.push_back(CGt02Position(114.216215,22.721995));
		m_vPosition.push_back(CGt02Position(114.223078,22.722135));
		m_vPosition.push_back(CGt02Position(114.228274,22.722138));
		m_vPosition.push_back(CGt02Position(114.231447,22.722191));
		m_vPosition.push_back(CGt02Position(114.236469,22.722314));
		m_vPosition.push_back(CGt02Position(114.23788,22.7214));
		m_vPosition.push_back(CGt02Position(114.240833,22.719906));
		m_vPosition.push_back(CGt02Position(114.244625,22.723666));
		m_vPosition.push_back(CGt02Position(114.247705,22.724428));
		m_vPosition.push_back(CGt02Position(114.247506,22.720716));
		m_vPosition.push_back(CGt02Position(114.2496,22.719677));
		m_vPosition.push_back(CGt02Position(114.256527,22.722379));
		m_vPosition.push_back(CGt02Position(114.260442,22.724436));
		m_vPosition.push_back(CGt02Position(114.2634351,22.72615986));
		m_vPosition.push_back(CGt02Position(114.267245,22.729039));
		m_vPosition.push_back(CGt02Position(114.270912,22.730881));
		m_vPosition.push_back(CGt02Position(114.276898,22.738331));
		m_vPosition.push_back(CGt02Position(114.277822,22.743955));
		m_vPosition.push_back(CGt02Position(114.278197,22.749084));
		m_vPosition.push_back(CGt02Position(114.2786987,22.75308967));
		m_vPosition.push_back(CGt02Position(114.291142,22.761614));
		m_vPosition.push_back(CGt02Position(114.299225,22.769262));
		m_vPosition.push_back(CGt02Position(114.3016515,22.77139913));
		m_vPosition.push_back(CGt02Position(114.3038557,22.77471833));
		m_vPosition.push_back(CGt02Position(114.310769,22.777058));
		m_vPosition.push_back(CGt02Position(114.310769,22.777058));
		m_vPosition.push_back(CGt02Position(114.304136,22.775559));
		m_vPosition.push_back(CGt02Position(114.302012,22.772221));
		m_vPosition.push_back(CGt02Position(114.299225,22.769262));
		m_vPosition.push_back(CGt02Position(114.292307,22.762514));
		m_vPosition.push_back(CGt02Position(114.284437,22.758465));
		m_vPosition.push_back(CGt02Position(114.280094,22.75572));
		m_vPosition.push_back(CGt02Position(114.277988,22.749852));
		m_vPosition.push_back(CGt02Position(114.277562,22.74457));
		m_vPosition.push_back(CGt02Position(114.276953,22.738347));
		m_vPosition.push_back(CGt02Position(114.271712,22.731501));
		m_vPosition.push_back(CGt02Position(114.267245,22.729039));
		m_vPosition.push_back(CGt02Position(114.26373,22.726816));
		m_vPosition.push_back(CGt02Position(114.260733,22.724988));
		m_vPosition.push_back(CGt02Position(114.250641,22.720228));
		m_vPosition.push_back(CGt02Position(114.250157,22.719983));
		m_vPosition.push_back(CGt02Position(114.247506,22.720716));
		m_vPosition.push_back(CGt02Position(114.247705,22.724428));
		m_vPosition.push_back(CGt02Position(114.244671,22.723688));
		m_vPosition.push_back(CGt02Position(114.242166,22.721573));
		m_vPosition.push_back(CGt02Position(114.23811,22.720646));
		m_vPosition.push_back(CGt02Position(114.236469,22.722314));
		m_vPosition.push_back(CGt02Position(114.23183,22.722493));
		m_vPosition.push_back(CGt02Position(114.227192,22.72256));
		m_vPosition.push_back(CGt02Position(114.223078,22.722135));
		m_vPosition.push_back(CGt02Position(114.216604,22.722234));
		m_vPosition.push_back(CGt02Position(114.2131409,22.71935064));
		m_vPosition.push_back(CGt02Position(114.213279,22.715061));
		m_vPosition.push_back(CGt02Position(114.215001,22.70758));
		m_vPosition.push_back(CGt02Position(114.220696,22.705243));
		m_vPosition.push_back(CGt02Position(114.2212005,22.70244913));
		m_vPosition.push_back(CGt02Position(114.214849,22.69599));
		m_vPosition.push_back(CGt02Position(114.206577,22.687595));
		m_vPosition.push_back(CGt02Position(114.093444,22.567873));
		m_vPosition.push_back(CGt02Position(114.099161,22.564115));
		m_vPosition.push_back(CGt02Position(114.099295,22.559255));
		m_vPosition.push_back(CGt02Position(114.0995173,22.55567667));
		m_vPosition.push_back(CGt02Position(114.099665,22.548263));
		m_vPosition.push_back(CGt02Position(114.09952,22.541731));
		m_vPosition.push_back(CGt02Position(114.097526,22.538412));
		m_vPosition.push_back(CGt02Position(114.093022,22.538372));
		m_vPosition.push_back(CGt02Position(114.079953,22.536661));
		m_vPosition.push_back(CGt02Position(114.077016,22.532247));
		m_vPosition.push_back(CGt02Position(114.073777,22.532087));
		m_vPosition.push_back(CGt02Position(114.064158,22.532082));
		m_vPosition.push_back(CGt02Position(114.056898,22.531905));
		m_vPosition.push_back(CGt02Position(114.051805,22.531725));
		m_vPosition.push_back(CGt02Position(114.038825,22.53099));
		m_vPosition.push_back(CGt02Position(114.033114,22.530452));
		m_vPosition.push_back(CGt02Position(114.021269,22.532338));
		m_vPosition.push_back(CGt02Position(114.019946,22.532341));
		m_vPosition.push_back(CGt02Position(113.997241,22.529545));
		m_vPosition.push_back(CGt02Position(113.985311,22.524048));
		m_vPosition.push_back(CGt02Position(113.966952,22.523237));
		m_vPosition.push_back(CGt02Position(113.938844,22.523997));
		m_vPosition.push_back(CGt02Position(113.931856,22.524204));
		m_vPosition.push_back(CGt02Position(113.928289,22.525368));
		m_vPosition.push_back(CGt02Position(113.922745,22.526356));
		m_vPosition.push_back(CGt02Position(113.919203,22.529087));
		m_vPosition.push_back(CGt02Position(113.920066,22.533541));
		m_vPosition.push_back(CGt02Position(113.916014,22.5355385));
		m_vPosition.push_back(CGt02Position(113.911747,22.535221));
		m_vPosition.push_back(CGt02Position(113.911536,22.535408));
		m_vPosition.push_back(CGt02Position(113.907786,22.531232));
		m_vPosition.push_back(CGt02Position(113.903574,22.530215));
		m_vPosition.push_back(CGt02Position(113.910011,22.531472));
	};

	virtual ~CDeviceSt02CMD0x10(){m_iState = THREAD_STOP;};
	
	bool IsRunning()
	{
		return (m_iState == THREAD_RUN);
	};
protected:

	void Run()
	{
		StGt02TermToSvrMsg objStGt02TermToSvrMsg;

		memset(&objStGt02TermToSvrMsg,0,sizeof(objStGt02TermToSvrMsg));

		objStGt02TermToSvrMsg.m_stHeader.m_ubCmd = 0x10;
		objStGt02TermToSvrMsg.m_stHeader.m_ubLength = 37;

		MyUtility::CBaseEncode::Bcd2ToAscii(m_imei.c_str(),m_imei.size(),1,(char *)&objStGt02TermToSvrMsg.m_stHeader.m_ullImei);

		objStGt02TermToSvrMsg.m_stHeader.m_usLAC=0x0000;
		objStGt02TermToSvrMsg.m_stHeader.m_usPrefix=PREFIX;

		int position_index=0;
		
		
		while(m_iState != THREAD_STOP)
		{
			if(position_index >= m_vPosition.size())
				position_index = 0;
		
			m_iState = THREAD_RUN;
			CGt02Time tTime;

			memcpy(objStGt02TermToSvrMsg.m_unContent.m_st0x10.m_szDateTime,tTime.Format().data(),6);
			

			objStGt02TermToSvrMsg.m_unContent.m_st0x10.m_ubSpeed=rand() %255;

			objStGt02TermToSvrMsg.m_unContent.m_st0x10.m_uiLatitude  = m_vPosition.at(position_index).m_uiLatitude;
			objStGt02TermToSvrMsg.m_unContent.m_st0x10.m_uiLongitude = m_vPosition.at(position_index).m_uiLongitude;

			objStGt02TermToSvrMsg.m_unContent.m_st0x10.m_usDitection = rand()%360;

			objStGt02TermToSvrMsg.m_unContent.m_st0x10.m_uiPostfix = POSTFIX;

			
			objStGt02TermToSvrMsg.m_stHeader.m_usVno=htons(position_index);

			if(42 != write(m_sock,&objStGt02TermToSvrMsg,42))
			{
				std::cout << "write error \r\n";
				
				break;
			}
			
			else
			{
				std::string sReq;
				sReq.append((char *)&objStGt02TermToSvrMsg,42); 
				std::cout << MyUtility::CBaseEncode::CharStrToHexStr(sReq)<< "\r\n";

			}

			sleep(m_intval);
			position_index++;
			
		}
		
		

	}
};



#endif //DEVICE_GT02_0x10_CPP
