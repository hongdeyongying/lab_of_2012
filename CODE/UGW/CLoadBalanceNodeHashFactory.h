// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CLoadBalanceNodeHashFactory_H_HEADER_INCLUDED_B3D577CA
#define CLoadBalanceNodeHashFactory_H_HEADER_INCLUDED_B3D577CA

#include <string>
#include <map>
using namespace std;

#include "CLoadBalanceNodeHash.h"

namespace MyTENPAYAPI {

// 全局变量
// map<string,CLoadBalanceNodeHash*(*)()> g_mCLoadBalanceNodeHashFactory;
// 
// 本地变量，用构造函数，添加方法。
// CLoadBalanceNodeHashFactory<T> g(inID);
// 
// 采用任何对象的成员函数，获取实例
// if(NULL!= g.GetInstance(inID))
//   g.DoSameThing();

// 全局变量
extern map<std::string,CLoadBalanceNodeHash*(*)()> g_mCLoadBalanceNodeHashFactory;
extern map<std::string,CLoadBalanceNodeHash*> g_mCLoadBalanceNodeHash;


//##ModelId=4C2AE66E0353
template <typename T>
class CLoadBalanceNodeHashFactory
{
  public:
    CLoadBalanceNodeHash* GetSingletonInstance(const std::string &inId)
    {
    		CLoadBalanceNodeHash * res = NULL;
			
			std::map<std::string,MyTENPAYAPI::CLoadBalanceNodeHash*>::iterator iter = g_mCLoadBalanceNodeHash.find(inId);
			
			if((iter == g_mCLoadBalanceNodeHash.end())||(iter->second == NULL))
			{
				if(g_mCLoadBalanceNodeHashFactory.find(inId) != g_mCLoadBalanceNodeHashFactory.end())
				{	
						res = g_mCLoadBalanceNodeHash[inId] = g_mCLoadBalanceNodeHashFactory[inId]();
				}
			}
			else
			{
				res = iter->second;
			}
			
    		return res ;
    	}
  public:
    //##ModelId=4C2AE6E30365
    CLoadBalanceNodeHashFactory(const std::string & inId)
    {
    //std::cout << __FILE__ << ":" << __LINE__ << inId << endl;		
		/*g_mCCheckerFactory[inId]=CCheckerFactory<T>::Method;*/
		
		std::map<std::string,CLoadBalanceNodeHash*(*)()>::iterator iter ;

		iter = g_mCLoadBalanceNodeHashFactory.find(inId);

		if(iter != g_mCLoadBalanceNodeHashFactory.end())
		{
			iter->second = CLoadBalanceNodeHashFactory<T>::Method;
		}
		else
		{
			g_mCLoadBalanceNodeHashFactory.insert(map<string,CLoadBalanceNodeHash*(*)()>::value_type(inId,CLoadBalanceNodeHashFactory<T>::Method));
		}
	
		//std::cout << __FILE__ << ":" << __LINE__ << inId << endl;
    }

    //##ModelId=4C2AE6E30393
    virtual ~CLoadBalanceNodeHashFactory()
    {
		std::map<std::string,MyTENPAYAPI::CLoadBalanceNodeHash*>::iterator iter ;
	
		for( iter = g_mCLoadBalanceNodeHash.begin(); iter != g_mCLoadBalanceNodeHash.end(); iter++)
		{
			if(NULL != iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
		
		g_mCLoadBalanceNodeHash.clear();
		//g_mCLoadBalanceNodeHashFactory.clear();
    };

    // 用指定名字获取相应的签名工具
    //##ModelId=4C2AE6EF0307
    CLoadBalanceNodeHash* GetInstance(const std::string &inId)
    {
    		CLoadBalanceNodeHash * res = NULL;
    		
    		if(g_mCLoadBalanceNodeHashFactory.find(inId) != g_mCLoadBalanceNodeHashFactory.end())
    			res = g_mCLoadBalanceNodeHashFactory[inId]();
    		
    		return res ;
    	}


    // 创建特定对象的方法
    //##ModelId=4C2AE6EF0336
    static CLoadBalanceNodeHash* Method()
    {
      return (CLoadBalanceNodeHash *)(new T);
    }


};
extern CLoadBalanceNodeHashFactory<CLoadBalanceNodeHash> g_CLoadBalanceNodeHashFactory;
} // namespace MyTENPAYAPI



#endif /* CLoadBalanceNodeHashFactory_H_HEADER_INCLUDED_B3D577CA */
