// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CTRANSACTION_MYSQL_H_HEADER_INCLUDED_B3EE7263
#define CTRANSACTION_MYSQL_H_HEADER_INCLUDED_B3EE7263

#include "mysoft_app.h"

#include "CTransaction.h"

#include <mysql++/mysql++.h>

#include "CConfigEntry.h"

#include "CBaseEncode.h"
#include "CStringVector.h"

namespace MyAPP {

class MySQLConnection{
private :
	mysqlpp::Connection * m_pConn;
	time_t m_iLast; 
	int m_iIdleTimeOut;
	
public :
	void SetIdleTimeOut(int s){m_iIdleTimeOut = s;};
	void SetValue(mysqlpp::Connection * right,int s)
	{
		m_iIdleTimeOut = s;
		m_iLast = time(NULL);
		m_pConn = right;
	};
	MySQLConnection():m_pConn(NULL),m_iLast(0),m_iIdleTimeOut(300){};
	~MySQLConnection()
	{
		if(m_pConn)	delete m_pConn;
		m_pConn = NULL;
	};
	
	int ping()
	{
		bool res = -1;
		time_t Cur = time(NULL);
		
		if(m_pConn)
		{
			if(abs(Cur - m_iLast) >= m_iIdleTimeOut)
			{		
				res = m_pConn->ping();
			}
			else
			{
				res = 0;
			}
			
		}

		if(res == 0)
			m_iLast = Cur;
		
		return res;
	}
	
	MySQLConnection & operator= (const MySQLConnection & right)
	{
		m_iLast = right.m_iLast;
		m_pConn = right.m_pConn;
		m_iIdleTimeOut = right.m_iIdleTimeOut;
	}
	MySQLConnection & operator= (mysqlpp::Connection * right)
	{
		m_iLast = time(NULL);
		m_pConn = right;
	}
	operator mysqlpp::Connection * ()
	{
		return m_pConn;
	}
};

// 测试用的东东
//##ModelId=4C11B36A03D2
class CTransaction_MYSQL : public MyCGI::CTransaction
{
  private:
	MyConfig::CConfigEntry * m_pConfig;
	
	
	typedef std::map<std::string ,MySQLConnection > CConnectionMap;
	
	CConnectionMap m_mpConnection;
   
   
	mysqlpp::Connection *GetConnect(const std::string &node);
	
	void Clear();
	int GetSQLParas(const std::string &sql , MyUtility::CStringVector & ioSV);
	
	const std::string GetServiceParameterDefault(const string & servic,const string & para);
	
  public:
	CTransaction_MYSQL();
	virtual ~CTransaction_MYSQL();
  
    virtual int Do(
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
	//配置文件
	MyConfig::CConfigEntry & config) throw(MyUtility::CMyException);
};

} // namespace MyAPP



#endif /* CTRANSACTION_MYSQL_H_HEADER_INCLUDED_B3EE7263 */
