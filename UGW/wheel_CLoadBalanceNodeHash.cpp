// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************
#include "wheel_CLoadBalanceNodeHash.h"
#include "CStringVector.h"
#include "CMyLogApi.h"

//##ModelId=4C3595FD02D5
void MyTENPAYAPI::wheel_CLoadBalanceNodeHash::Init(const std::string &inPara)
{
	static int iNode = 0;
	
	MyUtility::CStringVector sv;
	
	sv.Split(inPara,"|");
	
	if(0 < sv.size())
	{
		
		if(iNode >= sv.size()) iNode= 0;
		
		m_sNodePostfix = sv.at(iNode);
		iNode++;
	}
		
	
	
	
	DEBUG_LOGER <<  "MyTENPAYAPI::wheel_CLoadBalanceNodeHash::Init node=" <<m_sNodePostfix << LOGER_ETAG;
}

//##ModelId=4C3598580183
MyTENPAYAPI::wheel_CLoadBalanceNodeHash::wheel_CLoadBalanceNodeHash():CLoadBalanceNodeHash()
{
}


//##ModelId=4C35985801E1
MyTENPAYAPI::wheel_CLoadBalanceNodeHash::~wheel_CLoadBalanceNodeHash()
{
}
/*
//##ModelId=4C3598580200
const& wheel_CLoadBalanceNodeHash::GetDatabasePostfix() const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C35986E0126
const& CLoadBalanceNodeHash::GetDatabasePostfix(const std::string &inPara) const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C359858024F
const& wheel_CLoadBalanceNodeHash::GetNodePostfix() const
{
    return m_sNodePostfix;
}


//##ModelId=4C359858027D
const& wheel_CLoadBalanceNodeHash::GetNodePostfix(const std::string &inPara) const
{
    return m_sNodePostfix;
}


//##ModelId=4C35985802AC
const& wheel_CLoadBalanceNodeHash::GetTablePostfix() const
{
    return m_sTablePostfix;
}


//##ModelId=4C35985802DB
const& wheel_CLoadBalanceNodeHash::GetTablePostfix(const std::string &inPara) const
{
    return m_sTablePostfix;
}


//*/

MyTENPAYAPI::CLoadBalanceNodeHashFactory<MyTENPAYAPI::wheel_CLoadBalanceNodeHash> forwheel ("wheel");
