// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCHECKERFACTORY_H_HEADER_INCLUDED_B3E0A27E
#define CCHECKERFACTORY_H_HEADER_INCLUDED_B3E0A27E


#include "mysoft_cgi.h"

#include "CChecker.h"

namespace MyCGI {
// ȫ�ֱ���
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
    // ��ָ�����ֻ�ȡ��Ӧ��ת������
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


    // �����ض�����ķ���
    //##ModelId=4C1F124900E8
    static CChecker* Method()
    {
  		return (MyCGI::CChecker *)(new T);
     };


};

extern CCheckerFactory<CChecker> g_CCheckerFactory;

} // namespace MyCGI



#endif /* CCHECKERFACTORY_H_HEADER_INCLUDED_B3E0A27E */
