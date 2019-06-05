// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CTRANSACTIONFACTORY_H_HEADER_INCLUDED_B3E0CECC
#define CTRANSACTIONFACTORY_H_HEADER_INCLUDED_B3E0CECC

#include "mysoft_cgi.h"

#include "CTransaction.h"

namespace MyCGI {

// 全局变量
extern std::map<string,CTransaction*(*)()> g_mCTransactionFactory;
extern std::map<std::string,MyCGI::CTransaction*> g_mCTransaction;

//##ModelId=4C11EE2D00AA
template <typename T>
class CTransactionFactory
{
  public:
    CTransaction* GetSingletonInstance(const std::string &inId)
    {
    		CTransaction * res = NULL;
			
		std::map<std::string,MyCGI::CTransaction*>::iterator iter = g_mCTransaction.find(inId);
		
		if((iter == g_mCTransaction.end())||(iter->second == NULL))
		{
			if(g_mCTransactionFactory.find(inId) != g_mCTransactionFactory.end())
			{	
					res = g_mCTransaction[inId] = g_mCTransactionFactory[inId]();
			}
		}
			else
			{
				res = iter->second;
			}
			
    		return res ;
    	}
    // 用指定名字获取相应的转换工具
    // mode 0  无论什么时候都要  新分配 ,并交由调用方释放
    // mode 1  表示singleton，即只有一个实例，只创建一次
    //##ModelId=4C1F12F10333
    CTransaction* GetInstance(const std::string &inId)
    {
    		CTransaction * res = NULL;
			
	    		if(g_mCTransactionFactory.find(inId) != g_mCTransactionFactory.end())
    			{	
    				res = g_mCTransactionFactory[inId]();
	    		}
    		
    		return res ;
    	}


    //##ModelId=4C1F12F103B0
    CTransactionFactory(const std::string &inId)
    {
		//std::cout << __FILE__ << ":" << __LINE__ << inId <<endl;
		//g_mCTransactionFactory[inId]=CTransactionFactory<T>::Method;
		map<string,CTransaction*(*)()>::iterator iter ;

		iter = g_mCTransactionFactory.find(inId);

		if(iter != g_mCTransactionFactory.end())
		{
			iter->second = CTransactionFactory<T>::Method;
		}
		else
		{
			g_mCTransactionFactory.insert(map<string,CTransaction*(*)()>::value_type(inId,CTransactionFactory<T>::Method));
		}
		//std::cout << __FILE__ << ":" << __LINE__ << inId <<endl;
    }


    //##ModelId=4C1F12F103DF
    virtual ~CTransactionFactory()
    {
    	//g_mCTransactionFactory.clear();
    	std::map<std::string,MyCGI::CTransaction*>::iterator iter ;
	
		for( iter = g_mCTransaction.begin(); iter != g_mCTransaction.end(); iter++)
		{
			if(NULL != iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
		
		g_mCTransaction.clear();
    }


    // 创建特定对象的方法
    //##ModelId=4C1F12F20016
    static CTransaction* Method()
    {
      return (CTransaction *)(new T);
    }


};

extern CTransactionFactory<CTransaction> g_CTransactionFactory;
} // namespace MyCGI



#endif /* CTRANSACTIONFACTORY_H_HEADER_INCLUDED_B3E0CECC */
