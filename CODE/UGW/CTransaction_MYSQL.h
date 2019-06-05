// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
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

// �����õĶ���
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
        // �������
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // �������
        MyUtility::CStringVectorMap& outPara,
	//�����ļ�
	MyConfig::CConfigEntry & config) throw(MyUtility::CMyException);
};

} // namespace MyAPP



#endif /* CTRANSACTION_MYSQL_H_HEADER_INCLUDED_B3EE7263 */
