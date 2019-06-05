// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CTransaction_LDD.h"

#include "CTransactionFactory.h"

#include "CLDDGt02.h"

static CLDDGt02 objCLDDGt02;
static int iLddStatus = -1;


// StLastDeviceData *pStLastDeviceData =NULL;
static int Reg(const MyUtility::CStringVector & vImei,MyUtility::CStringVectorMap& outPara)
{
	if (iLddStatus != 0)
		iLddStatus = objCLDDGt02.Init();

	if (0 != iLddStatus )
	{
		LOGER_ERROR << "init ldd object error. retcode : " << iLddStatus << LOGER_ETAG;

		return iLddStatus;
	}

	int _record_num = 0;
	int _affected_row = 0;

	outPara["_field_name"].push_back("imei");
	outPara["_field_name"].push_back("longi");
	outPara["_field_name"].push_back("lati");
	outPara["_field_name"].push_back("dir");
	outPara["_field_name"].push_back("speed");
	outPara["_field_name"].push_back("status");
	outPara["_field_name"].push_back("tmgps");

	outPara["_field_name"].push_back("power");
	outPara["_field_name"].push_back("gsm_status");
	outPara["_field_name"].push_back("gps_status");
	outPara["_field_name"].push_back("snum");
	outPara["_field_name"].push_back("ssnrs"); // ,
	outPara["_field_name"].push_back("tmhb");

	outPara["_field_name"].push_back("mobile");
	outPara["_field_name"].push_back("tmaddr");

	outPara["_field_name"].push_back("exp");
	outPara["_field_name"].push_back("tmexp");

	
	outPara["_field_name"].push_back("isreg");
	

	for(int i=0;i < vImei.size() ;i++)
	{
		uint64_t imei=0 ;

		MyUtility::CBaseEncode::Bcd2ToAscii(vImei.at(i).c_str(),vImei.at(i).size(),1,(char *)&imei);

		StLastDeviceData *pStLastDeviceData =NULL;

		_record_num++;

		if (0 <= objCLDDGt02.Register(imei,pStLastDeviceData))
		{
				//std::cout << "dump memory by imei " << MyUtility::CBaseEncode::Hex(imei) << std::endl;
				//pStLastDeviceData->DumpInfo(LOGER_ERROR);
				LOGER_DEBUG << vImei.at(i) << LOGER_ETAG;
				

				outPara["imei"].push_back(vImei.at(i));
				outPara["longi"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_uiLongitue));
				outPara["lati"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_uiLatitude));
				outPara["dir"].push_back(MyUtility::CBaseEncode::IntToString(pStLastDeviceData->m_usDirection));
				outPara["speed"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubSpeed));
				outPara["status"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_uiStatus));
				outPara["tmgps"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmGpsData));

				outPara["power"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubPower));
				outPara["gsm_status"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubGsm));
				outPara["gps_status"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubGpsStatus));
				outPara["snum"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubSNumber));

				std::string ssnrs = "";
				for(int itmp = 0; itmp < 10 && itmp <pStLastDeviceData->m_ubSNumber ; itmp ++)
					ssnrs += MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubSSNR[itmp]) + "|";
				
				outPara["ssnrs"].push_back(ssnrs); // ,
				
				outPara["tmhb"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmHBData));

				outPara["mobile"].push_back(MyUtility::CBaseEncode::Hex(pStLastDeviceData->m_ubMobile,sizeof(pStLastDeviceData->m_ubMobile)));
				outPara["tmaddr"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmAddrData));

				outPara["exp"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubExp));
				outPara["tmexp"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmExpData));

				outPara["isreg"].push_back("1");
				
		}
		else
		{
				//std::cout << "\r\n#****imei not exist***" << MyUtility::CBaseEncode::Hex(imei) << std::endl;
				outPara["imei"].push_back(vImei.at(i));
				outPara["longi"].push_back("0");
				outPara["lati"].push_back("0");
				outPara["dir"].push_back("0");
				outPara["speed"].push_back("0");
				outPara["status"].push_back("0");
				outPara["tmgps"].push_back("0");

				outPara["power"].push_back("0");
				outPara["gsm_status"].push_back("0");
				outPara["gps_status"].push_back("0");
				outPara["snum"].push_back("0");
				outPara["ssnrs"].push_back("0"); // ,
				outPara["tmhb"].push_back("0");

				outPara["mobile"].push_back("0");
				outPara["tmaddr"].push_back("0");

				outPara["exp"].push_back("0");
				outPara["tmexp"].push_back("0");

				outPara["isreg"].push_back("0");
		}
	}

	outPara["_record_num"].push_back( MyUtility::CBaseEncode::IntToString(_record_num));

	outPara["_affected_row"].push_back(  MyUtility::CBaseEncode::IntToString(_affected_row));

	return 0;


}

	
	
static int ReadByImei(const MyUtility::CStringVector & vImei,MyUtility::CStringVectorMap& outPara)
{
	if (iLddStatus != 0)
		iLddStatus = objCLDDGt02.Init();

    if (0 != iLddStatus )
	{
		LOGER_ERROR << "init ldd object error. retcode : " << iLddStatus << LOGER_ETAG;

		return iLddStatus;
	}

	int _record_num = 0;
	int _affected_row = 0;


	outPara["_field_name"].push_back("imei");
	outPara["_field_name"].push_back("longi");
	outPara["_field_name"].push_back("lati");
	outPara["_field_name"].push_back("dir");
	outPara["_field_name"].push_back("speed");
	outPara["_field_name"].push_back("status");
	outPara["_field_name"].push_back("tmgps");

	outPara["_field_name"].push_back("power");
	outPara["_field_name"].push_back("gsm_status");
	outPara["_field_name"].push_back("gps_status");
	outPara["_field_name"].push_back("snum");
	outPara["_field_name"].push_back("ssnrs"); // ,
	outPara["_field_name"].push_back("tmhb");

	outPara["_field_name"].push_back("mobile");
	outPara["_field_name"].push_back("tmaddr");

	outPara["_field_name"].push_back("exp");
	outPara["_field_name"].push_back("tmexp");

	
	outPara["_field_name"].push_back("isreg");
	

    for(int i=0;i < vImei.size() ;i++)
    {
        uint64_t imei=0 ;

        MyUtility::CBaseEncode::Bcd2ToAscii(vImei.at(i).c_str(),vImei.at(i).size(),1,(char *)&imei);

        StLastDeviceData *pStLastDeviceData =NULL;

		_record_num++;

        if (0 == objCLDDGt02.GetByImei(imei,pStLastDeviceData))
        {
                //std::cout << "dump memory by imei " << MyUtility::CBaseEncode::Hex(imei) << std::endl;
                //pStLastDeviceData->DumpInfo(LOGER_ERROR);
				LOGER_DEBUG << vImei.at(i) << LOGER_ETAG;
				

				outPara["imei"].push_back(vImei.at(i));
				outPara["longi"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_uiLongitue));
				outPara["lati"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_uiLatitude));
				outPara["dir"].push_back(MyUtility::CBaseEncode::IntToString(pStLastDeviceData->m_usDirection));
				outPara["speed"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubSpeed));
				outPara["status"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_uiStatus));
				outPara["tmgps"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmGpsData));

				outPara["power"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubPower));
				outPara["gsm_status"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubGsm));
				outPara["gps_status"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubGpsStatus));
				outPara["snum"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubSNumber));

				std::string ssnrs = "";
				for(int itmp = 0; itmp < 10 && itmp <pStLastDeviceData->m_ubSNumber ; itmp ++)
					ssnrs += MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubSSNR[itmp]) + "|";
				
				outPara["ssnrs"].push_back(ssnrs); // ,
				
				outPara["tmhb"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmHBData));

				outPara["mobile"].push_back(MyUtility::CBaseEncode::Hex(pStLastDeviceData->m_ubMobile,sizeof(pStLastDeviceData->m_ubMobile)));
				outPara["tmaddr"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmAddrData));

				outPara["exp"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_ubExp));
				outPara["tmexp"].push_back(MyUtility::CBaseEncode::UIntToString(pStLastDeviceData->m_tmExpData));

				outPara["isreg"].push_back("1");
				
        }
        else
        {
                //std::cout << "\r\n#****imei not exist***" << MyUtility::CBaseEncode::Hex(imei) << std::endl;
                outPara["imei"].push_back(vImei.at(i));
				outPara["longi"].push_back("0");
				outPara["lati"].push_back("0");
				outPara["dir"].push_back("0");
				outPara["speed"].push_back("0");
				outPara["status"].push_back("0");
				outPara["tmgps"].push_back("0");

				outPara["power"].push_back("0");
				outPara["gsm_status"].push_back("0");
				outPara["gps_status"].push_back("0");
				outPara["snum"].push_back("0");
				outPara["ssnrs"].push_back("0"); // ,
				outPara["tmhb"].push_back("0");

				outPara["mobile"].push_back("0");
				outPara["tmaddr"].push_back("0");

				outPara["exp"].push_back("0");
				outPara["tmexp"].push_back("0");

				outPara["isreg"].push_back("0");
        }
    }

	outPara["_record_num"].push_back( MyUtility::CBaseEncode::IntToString(_record_num));

	outPara["_affected_row"].push_back( MyUtility::CBaseEncode::IntToString(_affected_row));

	return 0;


}



MyCGI::CTransaction_LDD::CTransaction_LDD()
{
	iLddStatus= objCLDDGt02.Init();
	
	if (0 != iLddStatus )
	{
		LOGER_ERROR << "init ldd object error. retcode : " << iLddStatus << LOGER_ETAG;
	}
}





int  MyCGI::CTransaction_LDD::Do(
        // 输入参数
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // 输出参数
        MyUtility::CStringVectorMap& outPara,
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException)
{
	int result = 0;

	// 验证是否登录

	// 读取METHOD 
	std::string t_sMethod = inPara.GetFirst("method"); 

	
	// 读取前台传递的IMEI
	MyUtility::CStringVectorMap::const_iterator iterImei = inPara.find("imei");
	if(iterImei == inPara.end()  ||  iterImei->second.size() <= 0)
	{
		LOGER_INFO << "no imei input ." << LOGER_ETAG ;
		outPara["retcode"].push_back("200122");
		outPara["retmsg"].push_back("no imei");
		return -1;
	}

	
	if(t_sMethod == "reg")
	{
		if( 0 != Reg(iterImei->second,outPara))
		{
			LOGER_INFO << "read ldd by imei error ." << LOGER_ETAG ;
			outPara["retcode"].push_back("10112");
			outPara["retmsg"].push_back("注册失败");
			return -1;
		}
	}
	else
	{
		// 判断要获取的imei是否可被uid读取
		

		// 读取imei指定设备的LDD数据，并组织返回
		if( 0 != ReadByImei(iterImei->second,outPara))
		{
			LOGER_INFO << "read ldd by imei error ." << LOGER_ETAG ;
			outPara["retcode"].push_back("10111");
			outPara["retmsg"].push_back("读取数据失败");
			return -1;
		}
	}	

	outPara["retcode"].push_back("0");
	outPara["retmsg"].push_back("ok");
	return 0;
}


static MyCGI::CTransactionFactory<MyCGI::CTransaction_LDD> for_CTransactionFactory_method("ldd");

