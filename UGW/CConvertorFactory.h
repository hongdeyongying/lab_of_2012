// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CCONVERTORFACTORY_H_HEADER_INCLUDED_B3E0FEF2
#define CCONVERTORFACTORY_H_HEADER_INCLUDED_B3E0FEF2

#include "mysoft_cgi.h"

#include "CConvertor.h"

namespace MyCGI {

// 全局变量
extern map<string,CConvertor*(*)()> g_mCConvertorFactory;
extern map<string,CConvertor*> g_mCConvertor;
// 
// 本地变量，用构造函数，添加方法。
// CConvertorFactory<T> a(inID);
// 
// 采用任何对象的成员函数，获取实例
// if(NULL!= g.GetInstance(inID))
//   g.DoSameThing();
// 
//##ModelId=4C11DBF9036C
template <typename T>
class CConvertorFactory
{
private:
  	T * m_pT;
  public:
    CConvertor* GetSingletonInstance(const std::string &inId)
    {
    		CConvertor * res = NULL;
			
		std::map<std::string,MyCGI::CConvertor*>::iterator iter = g_mCConvertor.find(inId);
		
		if((iter == g_mCConvertor.end())||(iter->second == NULL))
		{
			if(g_mCConvertorFactory.find(inId) != g_mCConvertorFactory.end())
			{	
					res = g_mCConvertor[inId] = g_mCConvertorFactory[inId]();
			}
		}
			else
			{
				res = iter->second;
			}
			
    		return res ;
    	}
  public:
    // 用指定名字获取相应的转换工具
    //##ModelId=4C11DC190330
    CConvertor* GetInstance(const std::string &inId)
    {
    		CConvertor * res = NULL;
    		
    		if(g_mCConvertorFactory.find(inId) != g_mCConvertorFactory.end())
    			res = g_mCConvertorFactory[inId]();
    		
    		return res ;
    	}/**/;


    //##ModelId=4C1F06F00009
    CConvertorFactory(const std::string &inId)
    {
		//std::cout << __FILE__ << ":" << __LINE__ << inId <<endl;
      //g_mCConvertorFactory[inID]=CConvertorFactory<T>::Method;
		
	  	map<string,CConvertor*(*)()>::iterator iter ;

		iter = g_mCConvertorFactory.find(inId);

		if(iter != g_mCConvertorFactory.end())
		{
			iter->second = CConvertorFactory<T>::Method;
		}
		else
		{
			g_mCConvertorFactory.insert(map<string,CConvertor*(*)()>::value_type(inId,CConvertorFactory<T>::Method));
		}
		
		//std::cout << __FILE__ << ":" << __LINE__ << inId <<endl;
    }/**/;


    //##ModelId=4C1F06F00067
    virtual ~CConvertorFactory()
    {
    	//g_mCTransactionFactory.clear();
    	std::map<std::string,MyCGI::CConvertor*>::iterator iter ;
	
		for( iter = g_mCConvertor.begin(); iter != g_mCConvertor.end(); iter++)
		{
			if(NULL != iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
		
		g_mCConvertor.clear();
    }


    // 创建特定对象的方法
    //##ModelId=4C1F071502C9
    static CConvertor *Method()
    {
      return (CConvertor *)(new T);
    }


};


extern CConvertorFactory<CConvertor> g_CConvertorFactory;
} // namespace MyCGI



#endif /* CCONVERTORFACTORY_H_HEADER_INCLUDED_B3E0FEF2 */
