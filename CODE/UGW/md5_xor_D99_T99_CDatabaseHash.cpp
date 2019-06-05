// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************
#include "md5_xor_D99_T99_CDatabaseHash.h"

//##ModelId=4C3595FD02D5
void MyAPP::md5_xor_D99_T99_CDatabaseHash::Init(const std::string &inPara)
{
	int iDb = 0, iTbl = 0;
	std::string md5Res,md5HexRes;
	
	md5(inPara,md5HexRes);
	
	DEBUG_LOGER <<  "MyAPP::md5_xor_D99_T99_CDatabaseHash::Init md5HexRes=" << md5HexRes << " size ="<< md5HexRes.size()<< LOGER_ETAG;
	
	md5Res = MyUtility::CBaseEncode::HexStrToCharStr(md5HexRes);
	
	int mid = md5Res.size()/2;
	std::string::const_iterator iter = md5Res.begin();
	
	DEBUG_LOGER <<  "MyAPP::md5_xor_D99_T99_CDatabaseHash::Init mid=" << mid << " size=" << md5Res.size()<< LOGER_ETAG;
	for (int i=0; iter != md5Res.end(); iter++,i++)
	{
		if(i < mid)
			iDb  ^= (unsigned char )*iter;
		else
			iTbl ^= (unsigned char )*iter;
	}
	iDb  %= 100;
	iTbl %= 100;
		
	DEBUG_LOGER <<  "MyAPP::md5_xor_D99_T99_CDatabaseHash::Init db=" <<iDb << " table=" << iTbl<< LOGER_ETAG;
	
	m_sDatabasePostfix = MyUtility::CBaseEncode::IntToString(iDb);	
	if(m_sDatabasePostfix.size() == 1)
		m_sDatabasePostfix = "0" +m_sDatabasePostfix;
		
	m_sTablePostfix = MyUtility::CBaseEncode::IntToString(iTbl);
	if(m_sTablePostfix.size() == 1)
		m_sTablePostfix = "0" +m_sTablePostfix;		
	
	DEBUG_LOGER <<  "MyAPP::md5_xor_D99_T99_CDatabaseHash::Init db=" <<m_sDatabasePostfix << " table=" << m_sTablePostfix<< LOGER_ETAG;
}

//##ModelId=4C3598580183
MyAPP::md5_xor_D99_T99_CDatabaseHash::md5_xor_D99_T99_CDatabaseHash():CDatabaseHash()
{
}


//##ModelId=4C35985801E1
MyAPP::md5_xor_D99_T99_CDatabaseHash::~md5_xor_D99_T99_CDatabaseHash()
{
}
/*
//##ModelId=4C3598580200
const& md5_xor_D99_T99_CDatabaseHash::GetDatabasePostfix() const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C35986E0126
const& CDatabaseHash::GetDatabasePostfix(const std::string &inPara) const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C359858024F
const& md5_xor_D99_T99_CDatabaseHash::GetNodePostfix() const
{
    return m_sNodePostfix;
}


//##ModelId=4C359858027D
const& md5_xor_D99_T99_CDatabaseHash::GetNodePostfix(const std::string &inPara) const
{
    return m_sNodePostfix;
}


//##ModelId=4C35985802AC
const& md5_xor_D99_T99_CDatabaseHash::GetTablePostfix() const
{
    return m_sTablePostfix;
}


//##ModelId=4C35985802DB
const& md5_xor_D99_T99_CDatabaseHash::GetTablePostfix(const std::string &inPara) const
{
    return m_sTablePostfix;
}


//*/

MyAPP::CDatabaseHashFactory<MyAPP::md5_xor_D99_T99_CDatabaseHash> formd5_xor_D99_T99 ("md5_xor_D99_T99");
