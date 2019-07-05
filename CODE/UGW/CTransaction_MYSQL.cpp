// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#include "CTransaction_MYSQL.h"

#include "CTransactionFactory.h"

#include "CDatabaseHashFactory.h"

#include "boost/regex.hpp"


#include "CVcdImg.h"

static  const long iMYSQL_PREPARE_CONFIG_ERROR = 10002001;


static const string sServiceName("mysql");
static const string sMethodName("method");

static const string sServiceNameSpace("mysql::");
//#ifndef DEFAULT_CTRANSACTION_MYSQL_CONFIG_FILE
//	#define DEFAULT_CTRANSACTION_MYSQL_CONFIG_FILE "./conf/mysql_index.conf.xml"
//static const std::string sCTRANSACTION_MYSQL_CONFIG_FILE("./conf/mysql_index.conf.xml");
//#endif
MyAPP::CTransaction_MYSQL::CTransaction_MYSQL()
{
	Clear();
//	m_pConfig->LoadConfig(DEFAULT_CTRANSACTION_MYSQL_CONFIG_FILE);
}
void MyAPP::CTransaction_MYSQL::Clear()
{
	CConnectionMap::iterator iter ;
	
	for( iter = m_mpConnection.begin(); iter != m_mpConnection.end(); iter++)
	{
		if(NULL != iter->second)
		{
			delete iter->second;
			iter->second = NULL;
		}
	}
}
MyAPP::CTransaction_MYSQL::~CTransaction_MYSQL()
{
	Clear();
	
}
mysqlpp::Connection *MyAPP::CTransaction_MYSQL::GetConnect(const std::string &node)
{
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::GetConnect(" << node << ")"<< LOGER_ETAG;	
	
	CConnectionMap::const_iterator iter ;
	
	iter = m_mpConnection.find(node);
	
	if(iter == m_mpConnection.end()) 
		m_mpConnection[node] = NULL;
		
	//检查对象的有效性
	if(NULL != m_mpConnection[node])
	{
		DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::GetConnect(" << node << ") Not NULL ,Checke valid connection by ping()"<< m_mpConnection[node].ping() << LOGER_ETAG;
		if(m_mpConnection[node].ping() != 0)
		{
			DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::GetConnect(" << node 
				<< ") Not NULL ,Checke valid connection by ping() -> invalid"<< LOGER_ETAG;
			INFO_LOGER << "Database 超时重连."<< LOGER_ETAG;
			delete m_mpConnection[node];
			m_mpConnection[node] = NULL;
		}
		else
		{
			DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::GetConnect(" << node 
				<< ") Not NULL ,Checke valid connection by ping() -> valid"<< LOGER_ETAG;
			return m_mpConnection[node];
		}
		
	}
	//创建链接对象
	if(NULL == m_mpConnection[node])	
	{
		DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::GetConnect(" << node << ")  NULL ,connecting ..."<< LOGER_ETAG;
		mysqlpp::Connection * pDb = NULL;
		try
		{
			pDb = new mysqlpp::Connection(true);
			
			pDb->connect(m_pConfig->GetService(node).GetVarVal("database").c_str(),
				m_pConfig->GetService(node).GetVarVal("host").c_str(),
				m_pConfig->GetService(node).GetVarVal("user").c_str(),
				m_pConfig->GetService(node).GetVarVal("passwd").c_str(),
				MyUtility::CBaseEncode::StringToInt(m_pConfig->GetService(node).GetVarVal("port"))/*,
				0,
				MyUtility::CBaseEncode::StringToInt(m_pConfig->GetService(node).GetVarVal("timeout"))*/
				);
				
			//change language
			mysqlpp::Query query = pDb->query();
			std::string lan = m_pConfig->GetService(node).GetVarVal("language");
			std::string lansql("SET NAMES ");
			if((!lan.empty())  && (lan != "default"))
			{
				lansql += lan;
				query.exec(lansql);  
			}

			int idletimeout = 300;

			idletimeout = MyUtility::CBaseEncode::StringToInt(m_pConfig->GetService(node).GetVarVal("idle_timeout")) ;

			if(idletimeout == 0)
				idletimeout = 300;
			m_mpConnection[node].SetValue(pDb,idletimeout);
						
			return m_mpConnection[node];
		}
		catch(const mysqlpp::Exception& er)
		{
			if(pDb != NULL)
				delete pDb;
			
			ERROR_LOGER << er.what() ;			
		}
		catch(MyUtility::CMyException & err)
		{
			if(pDb != NULL)
				delete pDb;
			
			ERROR_LOGER << err.ToString() ;
		}
		catch(...)
		{
			if(pDb != NULL)
				delete pDb;
				
			ERROR_LOGER << "Error while GetRealConnection.";
		}
	}
	
	//返回对象
	return m_mpConnection[node];
}

int  MyAPP::CTransaction_MYSQL::GetSQLParas(const std::string &sql , MyUtility::CStringVector & ioSV)
{
	ioSV.clear();
	
	static const char* re = "([$]{1})([a-zA-Z:_0-9]+)([$]{1})";
	static boost::regex expression(re, boost::regex_constants::normal);
	
	std::string::const_iterator start, end;
	start = sql.begin();
	end = sql.end();
	
	boost::match_results<std::string::const_iterator> what;
	boost::match_flag_type flags = boost::match_default | boost::match_any;
/*
	typedef std::pair<std::string, int> pair_type;
	typedef std::vector<pair_type> vec_type;
	vec_type v1;    //full
	vec_type v2;     // contain $
	vec_type v3;     // contain a-zA-Z0-9
	vec_type v4;     // contain $

	pair_type a;
	a.first = "___________________";
	a.second = 0;
	//*/
	//	std::cout << __FILE__ << " " << __LINE__ << " " << what.size() << " " << sql<< std::endl;

	while (boost::regex_search(start, end, what, expression, flags))
	{
	//	std::cout << __FILE__ << " " << __LINE__ << " " << what.size() << std::endl;
             //pair_type r;
             std::string::const_iterator temp = end;
			 /*
             if (what[0].matched)  //$aaa$
             {
                     r.first = std::string(what[0].first, what[0].second);
                     r.second = what[0].first - file.begin();
                     v1.push_back(r);

                     temp = what[0].second;
              }
              if (what[1].matched)      // $
              {
                   r.first = string(what[1].first, what[1].second);
                   r.second = what[1].first - file.begin();
				   v2.push_back(r);

                   if (temp - what[1].second > 0)
                   temp = what[1].second;
              }//*/

              if (what[2].matched) //aaa
              {
					 ioSV.push_back(string(what[2].first, what[2].second));
                     //r.first = string(what[2].first, what[2].second);
                     //r.second = what[2].first - file.begin();
                     //v3.push_back(r);

                     if (temp - what[2].second > 0)
						temp = what[2].second;
              }/*
              if (what[3].matched) // $
              {
                     r.first = string(what[3].first, what[3].second);
                     r.second = what[3].first - file.begin();
                     v4.push_back(r);

                     if (temp - what[3].second > 0)
                     temp = what[3].second;
              }
			  //*/


              start = temp;
              flags = boost::match_default | boost::match_any;
       }
/*
       res.insert(res.end(),v1.begin(),v1.end());
        res.push_back(a);
       res.insert(res.end(),v2.begin(),v2.end());
        res.push_back(a);
       res.insert(res.end(),v3.begin(),v3.end());
        res.push_back(a);
       res.insert(res.end(),v4.begin(),v4.end());
//*/
	return ioSV.size();
}

const std::string MyAPP::CTransaction_MYSQL::GetServiceParameterDefault(const string & servic,const string & para)
{
	std::string res("");
	
	if((m_pConfig) && (m_pConfig->IsExistService(servic)))
	{
	
		const MyConfig::CParameterVectorMap &mvPara =  m_pConfig->GetService(servic).GetParameterVectorMap();
		
		MyConfig::CParameterVectorMap::const_iterator iter = mvPara.find(para) ;
		if(iter != mvPara.end())
			res = iter->second.at(0).GetDefault();
	}
	
	return res;
}
//##ModelId=4C11DABC033C
int  MyAPP::CTransaction_MYSQL::Do(
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
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException)
{
	int result = 0;
	
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do" << LOGER_ETAG;		
	m_pConfig = &config;	
	
	// 获取节点名，数据库名，表名
	CDatabaseHash *pCDatabaseHash = NULL;
	
	std::string node ,method;
	
	
	std::string hash_method("fix"),node_prefix(""),hash_para(""), hash_str("");

	method = sServiceNameSpace + inPara.GetFirst(sMethodName);
	
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do  method = " << method<< LOGER_ETAG;	

	// 如果需要检查登录态  login_check
	if(m_pConfig->GetService(method).GetVarVal("login_check") != "false")
	{
		CVcdImg objCVcdImg;
		std::string outToken;
		
		MyUtility::CStringMap::const_iterator iterCookie = inCookie.find("sid");
		MyUtility::CStringMap::const_iterator iterCookieUid = inCookie.find("uid");
		
		if((iterCookie == inCookie.end()) && (iterCookieUid == inCookie.end()) )
		{
			LOGER_INFO<< "cookie  sid uid  " << result << LOGER_ETAG;	

			ERROR_RETURN("10002013","会话无效，请重新登录",outPara);	
		}
		result = objCVcdImg.LoginCheck(iterCookieUid->second,iterCookie->second,outToken);

		
		if(0 != result)
		{
			LOGER_INFO<< "objCVcdImg.LoginCheck return " << result << LOGER_ETAG;	

			ERROR_RETURN("10002013","会话过期，请重新登录",outPara);			
		}

		

//Set-Cookie: vcdid=<my-soft::echo type="expr" value=="Vector.At(Map.GetValueByKey($_RAW_REQUEST_STRING_VECTOR_MAP,vcdmd5),0)" />; PATH=/; DOMAIN=wucar.com;
		outPara["_COOKIE_"].push_back("Set-Cookie:sid="
			+outToken
			+"; PATH=/; DOMAIN="
			+m_pConfig->GetService(sServiceName).GetVarVal("_domain")
			+";\r\n");
	}
	
	// 如果需要检查验证码  vcdimg_check
	if(m_pConfig->GetService(method).GetVarVal("vcdimg_check") == "true")
	{
		CVcdImg objCVcdImg;

		MyUtility::CStringMap::const_iterator iterCookie = inCookie.find("vcdid");
		if(iterCookie != inCookie.end()) 
			result = objCVcdImg.Check(inPara.GetFirst("vcd"),iterCookie->second);

		
		if(iterCookie == inCookie.end() ||  (0 != result))
		{
			LOGER_INFO<< "objCVcdImg.Check"<< iterCookie->second << " " << inPara.GetFirst("vcd") <<" return " << result << LOGER_ETAG;	

			ERROR_RETURN("10002011","验证码无效或过期",outPara);
			
		}
	}
	
	hash_str = m_pConfig->GetService(method).GetVarVal("node");
	
	MyUtility::CStringVector sv,sv2;
	sv.Split(hash_str,":");
	
	hash_method = sv[0];
	if( sv.size() == 2)
	{
		sv2.Split(sv[1],",");
	
		node_prefix = sv2[0];
		if(sv2.size() == 2)	hash_para = sv2[1];
	}
			
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::pre  create pCDatabaseHash = " << hash_method<< LOGER_ETAG;	
	
	pCDatabaseHash = g_CDatabaseHashFactory.GetSingletonInstance(hash_method);
	
	if(NULL == pCDatabaseHash)
	{
		DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::error in  create pCDatabaseHash = " << hash_method<< LOGER_ETAG;	
		throw(MyUtility::CMyException("Error in CTransaction_MYSQL hashdatabase"),iMYSQL_PREPARE_CONFIG_ERROR);
		result = 10;
		return result;
		
	}
	
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do  create pCDatabaseHash = " << hash_method<< LOGER_ETAG;	
	//离散参数
	{
			MyUtility::CStringVector vsParas;
			int iParas = GetSQLParas(hash_para,vsParas);
			
			DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do  hash_para = " << hash_para << "\r\n"<< vsParas.Join("\r\n")<< LOGER_ETAG;	
			for(int i =0; i < iParas; i++)
			{
				std::string name = "$" + vsParas[i] + "$";
				
				std::string value("");
			
				MyUtility::CStringVectorMap::const_iterator iter;
				
				iter = inPara.find(vsParas[i]);
					
				value = GetServiceParameterDefault(sServiceName,vsParas[i]);
				
				if(iter != inPara.end())
				{
					value = iter->second.at(0);
				}
					
				MyUtility::CBaseEncode::StrReplace(hash_para,name,value);
			
			}
			DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do afte process hash_para = " << hash_para << "\r\n"
				<< vsParas.Join("\r\n")<< LOGER_ETAG;	
			
			pCDatabaseHash->Init(hash_para);
			
			DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do \r\nnode = " <<  pCDatabaseHash->GetNodePostfix()
				<<" \r\ndatabase = " << pCDatabaseHash->GetDatabasePostfix()
				<<" \r\ntable = " << pCDatabaseHash->GetTablePostfix()<< LOGER_ETAG ;
	}
	
	node = sServiceNameSpace + node_prefix + pCDatabaseHash->GetNodePostfix();
	
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do node = " << node<< LOGER_ETAG;	
	
	//
	mysqlpp::Connection *pConn = GetConnect(node);
	
	if(NULL == pConn)
	{
		sv.push_back("10002010");		
		outPara["retcode"] = sv;
		
		
		sv[0] = "Connect MYSQL error";
		
		outPara["retmsg"] = sv;

		Clear();
		
		return 12;

	}
	DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::GetConnection success and excute sql" << node<< LOGER_ETAG;	
	try
	{
		// 
		mysqlpp::Query query = pConn->query();
		//获取SQL
		std::string sql = m_pConfig->GetService(method).GetVarVal("sql");
		
		DEBUG_LOGER << sql<< LOGER_ETAG;	
		MyUtility::CBaseEncode::UrlDecode(sql);		
		DEBUG_LOGER << sql<< LOGER_ETAG;	
		
		//确认sql中需要补充的参数列表
		MyUtility::CStringVector vsParas;
		int iParas = GetSQLParas(sql,vsParas);
		DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do  sql_para = " << sql << "\r\n"<< vsParas.Join("\r\n")<< LOGER_ETAG;	
		
		for(int i =0; i < iParas; i++)
		{
			std::string name = "$" + vsParas[i] + "$";
			
			std::string value("");
		
			MyUtility::CStringVectorMap::const_iterator iter;

			iter = inPara.find(vsParas[i]);
			
			if(vsParas[i] == "field")//替换录入的标准参数 field offset limit 
			{
				value = GetServiceParameterDefault(method,vsParas[i]);				
				
				if(iter != inPara.end())
				{
					value = iter->second.Join(",");	
				}
			}
			else if(vsParas[i] == "database_postfix")//替换库和表  ?database_postfix?  ?table_postfix?
			{
				value =  pCDatabaseHash->GetDatabasePostfix();
			}
			else if(vsParas[i] == "table_postfix")//替换库和表  ?database_postfix?  ?table_postfix?
			{
				value =  pCDatabaseHash->GetTablePostfix();
			}
			else if(vsParas[i] == "offset")//offset
			{
				value = GetServiceParameterDefault(method,vsParas[i]);	
				
				if(iter != inPara.end())
				{
					value = iter->second.at(0);
				}
			}
			else if(vsParas[i] == "limit")//offset
			{
				value = GetServiceParameterDefault(method,vsParas[i]);	
				
				if(iter != inPara.end())
				{
					value = iter->second.at(0);
				}
			}
			else 
			{
				
				value = GetServiceParameterDefault(method,vsParas[i]);
				
				ostringstream stmp;
				
				if(iter != inPara.end())
				{
					value = iter->second.at(0);
					
					stmp<< mysqlpp::escape << value ;
					
					value = stmp.str();
				}
				else  // 试下cookie
				{
					MyUtility::CStringMap::const_iterator iter;
					if((iter = inCookie.find(vsParas[i])) != inCookie.end())
						value = iter->second;

					stmp<< mysqlpp::escape << value ;
					
					value = stmp.str();
				}				
				
				DEBUG_LOGER << "MyAPP::CTransaction_MYSQL::Do " <<  vsParas[i] <<" = " << value<< LOGER_ETAG;
				
			}
				
			MyUtility::CBaseEncode::StrReplace(sql,name,value);
		
		}
		
		
		
		
		
		
		
		/*
		ostringstream stest,otest;
		
		std::string aa = "\";\";;select \r\n\'* from db;/**''";
		
		otest << mysqlpp::escape << aa << mysqlpp::escape <<"[\t\"]"<<std::ends;
		
		stest << mysqlpp::escape << "\";\";;select \r\n\'* from db;/**''" << "[\t]" << std::ends;
		
		DEBUG_LOGER << otest.str();	
		DEBUG_LOGER << stest.str();	//*/
		
		DEBUG_LOGER << sql<< LOGER_ETAG;	
		
		query << sql << std::ends;
	
		mysqlpp::StoreQueryResult res = query.store();  

		outPara["_affected_row"].push_back(MyUtility::CBaseEncode::IntToString(query.affected_rows()));


		// clear result
		while( query.more_results())
		{
		   	query.store_next();                
			DEBUG_LOGER << "more than one result."; 
		}
		
		outPara["_record_num"].push_back(MyUtility::CBaseEncode::IntToString(res.size()));
		
		for(unsigned int  i =0 ;i < res.size();i++)
		{
			mysqlpp::Row row;     
			row = res.at(i);
			for(unsigned int j = 0; j < row.size(); j++)
			{
				if(i == 0)
				{
					outPara["_field_name"].push_back(res.field_name(j));
				}
				outPara[res.field_name(j)].push_back(row.at(j).c_str()/*get_string()*/);
			}
		}      

		// 如果需要更新登录态  login_check
		if((res.size() == 1 ) &&  (m_pConfig->GetService(method).GetVarVal("login_gen") == "true"))
		{
			CVcdImg objCVcdImg;
			std::string outToken;
			
			result = objCVcdImg.LoginGen(outPara.GetFirst("fid"),outToken);

			LOGER_DEBUG << "uid " << outPara.GetFirst("fid") << " " << outPara.GetFirst("femail") << LOGER_ETAG;

			
			if(0 != result)
			{
				LOGER_INFO<< "objCVcdImg.LoginGen return " << result << LOGER_ETAG;	

				ERROR_RETURN("10002013","登录系统繁忙，请稍后再试",outPara);			
			}

			

	//Set-Cookie: vcdid=<my-soft::echo type="expr" value=="Vector.At(Map.GetValueByKey($_RAW_REQUEST_STRING_VECTOR_MAP,vcdmd5),0)" />; PATH=/; DOMAIN=wucar.com;
			outPara["_COOKIE_"].push_back("Set-Cookie:sid="
				+outToken
				+"; PATH=/; DOMAIN="
				+m_pConfig->GetService(sServiceName).GetVarVal("_domain")
				+";\r\n");
			outPara["_COOKIE_"].push_back("Set-Cookie:uid="
				+outPara.GetFirst("fid")
				+"; PATH=/; DOMAIN="
				+m_pConfig->GetService(sServiceName).GetVarVal("_domain")
				+";\r\n");
			outPara["_COOKIE_"].push_back("Set-Cookie:femail="
				+outPara.GetFirst("femail")
				+"; PATH=/; DOMAIN="
				+m_pConfig->GetService(sServiceName).GetVarVal("_domain")
				+";\r\n");
			
			outPara["_COOKIE_"].push_back("Set-Cookie:displayname="
				+MyUtility::CBaseEncode::UrlEncode2(outPara.GetFirst("fdisplay_name"))
				+"; PATH=/; DOMAIN="
				+m_pConfig->GetService(sServiceName).GetVarVal("_domain")
				+";\r\n");
	
		}
				
		//gen rsppack 
		sv.clear();
		sv.push_back("0");		
		outPara["retcode"] = sv;
		
		sv[0] = "success";		
		outPara["retmsg"] = sv;
		
		
		//DEBUG_LOGER << outPara.Join("&","=");	
		
		return 0;
	}
	catch(const mysqlpp::Exception& er)
	{
		ERROR_LOGER << er.what() ;			
		
		
		sv.clear();
		sv.push_back("10002012");		
		outPara["retcode"] = sv;
		
		sv[0] = er.what();		
		outPara["retmsg"] = sv;

		Clear();
	}
	
	return result;
}

static MyCGI::CTransactionFactory<MyAPP::CTransaction_MYSQL> for_CTransactionFactory_method(sServiceName);
