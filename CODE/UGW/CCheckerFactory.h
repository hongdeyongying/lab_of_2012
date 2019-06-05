// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CCHECKERFACTORY_H_HEADER_INCLUDED_B3E0A27E
#define CCHECKERFACTORY_H_HEADER_INCLUDED_B3E0A27E


#include "mysoft_cgi.h"

#include "CChecker.h"

namespace MyCGI {
// 全局变量
extern map<string,CChecker*(*)()> g_mCCheckerFactory;
extern map<string,CChecker*> g_mCChecker;

//##ModelId=4BF65E4D03E5
template <typename T>
class CCheckerFactory
{
  public:
    CChecker* GetSingletonInstance(const std::string &inId)
    {
    		CChecker * res = NULL;
			
		std::map<std::string,MyCGI::CChecker*>::iterator iter = g_mCChecker.find(inId);
		
		if((iter == g_mCChecker.end())||(iter->second == NULL))
		{
			if(g_mCCheckerFactory.find(inId) != g_mCCheckerFactory.end())
			{	
					res = g_mCChecker[inId] = g_mCCheckerFactory[inId]();
			}
		}
			else
			{
				res = iter->second;
			}
		
			
    		return res ;
    	}
    // 用指定名字获取相应的转换工具
    // 
    // map<string , CChecker*(*)() >g_mCCheckerFactory
    //##ModelId=4C1F1249003D
    CChecker* GetInstance(const std::string &inId)
    {
		 MyCGI::CChecker * res = NULL;
		
		if( MyCGI::g_mCCheckerFactory.find(inId) !=  MyCGI::g_mCCheckerFactory.end())
			res =  MyCGI::g_mCCheckerFactory[inId]();
		
		return res ;
    };

	virtual ~CCheckerFactory()
	{
		//g_mCTransactionFactory.clear();
    		std::map<std::string,MyCGI::CChecker*>::iterator iter ;
	
		for( iter = g_mCChecker.begin(); iter != g_mCChecker.end(); iter++)
		{
			if(NULL != iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
		
		g_mCChecker.clear();
	}
    //##ModelId=4C1F1249009A
    CCheckerFactory(const std::string &inId)
	{
		//*debugLoger << __FILE__ << ":" << __LINE__ << inId << endl;		
		/*g_mCCheckerFactory[inId]=CCheckerFactory<T>::Method;*/
		
		std::map<std::string,CChecker*(*)()>::iterator iter ;

		iter = g_mCCheckerFactory.find(inId);

		if(iter != g_mCCheckerFactory.end())
		{
			iter->second = CCheckerFactory<T>::Method;
		}
		else
		{
			g_mCCheckerFactory.insert(map<string,CChecker*(*)()>::value_type(inId,CCheckerFactory<T>::Method));
		}
	
		//*debugLoger << __FILE__ << ":" << __LINE__ << inId << endl;
	};


    // 创建特定对象的方法
    //##ModelId=4C1F124900E8
    static CChecker* Method()
    {
  		return (MyCGI::CChecker *)(new T);
     };


};

extern CCheckerFactory<CChecker> g_CCheckerFactory;

} // namespace MyCGI



#endif /* CCHECKERFACTORY_H_HEADER_INCLUDED_B3E0A27E */
