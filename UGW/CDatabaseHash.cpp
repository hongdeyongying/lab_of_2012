// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************
#include "CDatabaseHash.h"

//##ModelId=4C3595FD02D5
void MyAPP::CDatabaseHash::Init(const std::string &inPara)
{
	
}

//##ModelId=4C3598580183
MyAPP::CDatabaseHash::CDatabaseHash():m_sDatabasePostfix(""),m_sNodePostfix(""),m_sTablePostfix("")
{
}


//##ModelId=4C35985801E1
MyAPP::CDatabaseHash::~CDatabaseHash()
{
}

//##ModelId=4C3598580200
const std::string & MyAPP::CDatabaseHash::GetDatabasePostfix() const
{
    return m_sDatabasePostfix;
}


//##ModelId=4C35986E0126
const std::string & MyAPP::CDatabaseHash::GetDatabasePostfix(const std::string &inPara) 
{
	Init(inPara);
    return m_sDatabasePostfix;
}


//##ModelId=4C359858024F
const std::string &MyAPP::CDatabaseHash::GetNodePostfix() const
{
    return m_sNodePostfix;
}


//##ModelId=4C359858027D
const std::string & MyAPP::CDatabaseHash::GetNodePostfix(const std::string &inPara) 
{
	Init(inPara);
    return m_sNodePostfix;
}


//##ModelId=4C35985802AC
const std::string & MyAPP::CDatabaseHash::GetTablePostfix() const
{
    return m_sTablePostfix;
}


//##ModelId=4C35985802DB
const std::string & MyAPP::CDatabaseHash::GetTablePostfix(const std::string &inPara)
{
	Init(inPara);
    return m_sTablePostfix;
}


