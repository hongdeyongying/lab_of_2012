#include "CDigitalSignature.h"
// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CDIGITALSIGNATUREFACTORY_H_HEADER_INCLUDED_B3D577CA
#define CDIGITALSIGNATUREFACTORY_H_HEADER_INCLUDED_B3D577CA

#include "mysoft_cgi.h"

#include "CDigitalSignature.h"

namespace MyCGI {

// 全局变量
// map<string,CDigitalSignature*(*)()> g_mCDigitalSignatureFactory;
// 
// 本地变量，用构造函数，添加方法。
// CDigitalSignatureFactory<T> g(inID);
// 
// 采用任何对象的成员函数，获取实例
// if(NULL!= g.GetInstance(inID))
//   g.DoSameThing();

// 全局变量
extern map<std::string,CDigitalSignature*(*)()> g_mCDigitalSignatureFactory;
extern map<std::string,CDigitalSignature*> g_mCDigitalSignature;


//##ModelId=4C2AE66E0353
template <typename T>
class CDigitalSignatureFactory
{
  public:
    CDigitalSignature* GetSingletonInstance(const std::string &inId)
    {
    		CDigitalSignature * res = NULL;
			
		std::map<std::string,MyCGI::CDigitalSignature*>::iterator iter = g_mCDigitalSignature.find(inId);
		
		if((iter == g_mCDigitalSignature.end())||(iter->second == NULL))
		{
			if(g_mCDigitalSignatureFactory.find(inId) != g_mCDigitalSignatureFactory.end())
			{	
					res = g_mCDigitalSignature[inId] = g_mCDigitalSignatureFactory[inId]();
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
    CDigitalSignatureFactory(const std::string & inId)
    {
    //std::cout << __FILE__ << ":" << __LINE__ << inId << endl;		
		/*g_mCCheckerFactory[inId]=CCheckerFactory<T>::Method;*/
		
		std::map<std::string,CDigitalSignature*(*)()>::iterator iter ;

		iter = g_mCDigitalSignatureFactory.find(inId);

		if(iter != g_mCDigitalSignatureFactory.end())
		{
			iter->second = CDigitalSignatureFactory<T>::Method;
		}
		else
		{
			g_mCDigitalSignatureFactory.insert(map<string,CDigitalSignature*(*)()>::value_type(inId,CDigitalSignatureFactory<T>::Method));
		}
	
		//std::cout << __FILE__ << ":" << __LINE__ << inId << endl;
    }

    //##ModelId=4C2AE6E30393
    virtual ~CDigitalSignatureFactory()
    {
    	//g_mCTransactionFactory.clear();
    	std::map<std::string,MyCGI::CDigitalSignature*>::iterator iter ;
	
		for( iter = g_mCDigitalSignature.begin(); iter != g_mCDigitalSignature.end(); iter++)
		{
			if(NULL != iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
		
		g_mCDigitalSignature.clear();
    };

    // 用指定名字获取相应的签名工具
    //##ModelId=4C2AE6EF0307
    MyCGI::CDigitalSignature* GetInstance(const std::string &inId)
    {
    		CDigitalSignature * res = NULL;
    		
    		if(g_mCDigitalSignatureFactory.find(inId) != g_mCDigitalSignatureFactory.end())
    			res = g_mCDigitalSignatureFactory[inId]();
    		
    		return res ;
    	}


    // 创建特定对象的方法
    //##ModelId=4C2AE6EF0336
    static MyCGI::CDigitalSignature* Method()
    {
      return (CDigitalSignature *)(new T);
    }


};
extern CDigitalSignatureFactory<CDigitalSignature> g_CDigitalSignatureFactory;
} // namespace MyCGI



#endif /* CDIGITALSIGNATUREFACTORY_H_HEADER_INCLUDED_B3D577CA */
