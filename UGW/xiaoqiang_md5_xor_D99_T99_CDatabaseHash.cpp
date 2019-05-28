// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************
#include "xiaoqiang_md5_xor_D99_T99_CDatabaseHash.h"

//##ModelId=4C3595FD02D5
void MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::Init(const std::string &inPara)
{
	int iDb = 0, iTbl = 0;
	std::string md5Res,md5HexRes;
	
	md5(inPara,md5HexRes);
	
	DEBUG_LOGER <<  "MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::Init md5HexRes=" << md5HexRes << " size ="<< md5HexRes.size()<< LOGER_ETAG;
	
	md5Res = MyUtility::CBaseEncode::HexStrToCharStr(md5HexRes);
	
	std::string::const_iterator iter = md5Res.begin();
	
	for (int i=0; iter != md5Res.end(); iter++,i++)
	{
		if(i >= 12)  // 基于xiaoqiang的错误计算
		{
		if(i %2 == 0)
			iDb  ^= (unsigned char )*iter;
		else
			iTbl ^= (unsigned char )*iter;
		}
	}
	DEBUG_LOGER <<  "MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::Init db=" <<iDb << " table=" << iTbl<< LOGER_ETAG;
	iDb  %= 100;
	iTbl %= 100;
		
	DEBUG_LOGER <<  "MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::Init db=" <<iDb << " table=" << iTbl<< LOGER_ETAG;
	
	m_sDatabasePostfix = MyUtility::CBaseEncode::IntToString(iDb);	
	if(m_sDatabasePostfix.size() == 1)
		m_sDatabasePostfix = "0" +m_sDatabasePostfix;
		
	m_sTablePostfix = MyUtility::CBaseEncode::IntToString(iTbl);
	if(m_sTablePostfix.size() == 1)
		m_sTablePostfix = "0" +m_sTablePostfix;		
	
	DEBUG_LOGER <<  "MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::Init db=" <<m_sDatabasePostfix << " table=" << m_sTablePostfix<< LOGER_ETAG;
}

//##ModelId=4C3598580183
MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::xiaoqiang_md5_xor_D99_T99_CDatabaseHash():CDatabaseHash()
{
}


//##ModelId=4C35985801E1
MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash::~xiaoqiang_md5_xor_D99_T99_CDatabaseHash()
{
}
/*
//##ModelId=4C3598580200
const& xiaoqiang_md5_xor_D99_T99_CDatabaseHash::GetDatabasePostfix() const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C35986E0126
const& CDatabaseHash::GetDatabasePostfix(const std::string &inPara) const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C359858024F
const& xiaoqiang_md5_xor_D99_T99_CDatabaseHash::GetNodePostfix() const
{
    return m_sNodePostfix;
}


//##ModelId=4C359858027D
const& xiaoqiang_md5_xor_D99_T99_CDatabaseHash::GetNodePostfix(const std::string &inPara) const
{
    return m_sNodePostfix;
}


//##ModelId=4C35985802AC
const& xiaoqiang_md5_xor_D99_T99_CDatabaseHash::GetTablePostfix() const
{
    return m_sTablePostfix;
}


//##ModelId=4C35985802DB
const& xiaoqiang_md5_xor_D99_T99_CDatabaseHash::GetTablePostfix(const std::string &inPara) const
{
    return m_sTablePostfix;
}


//*/

MyAPP::CDatabaseHashFactory<MyAPP::xiaoqiang_md5_xor_D99_T99_CDatabaseHash> forxiaoqiang_md5_xor_D99_T99 ("xiaoqiang_md5_xor_D99_T99");
