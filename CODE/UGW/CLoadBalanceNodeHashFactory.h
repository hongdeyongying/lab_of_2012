// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CLoadBalanceNodeHashFactory_H_HEADER_INCLUDED_B3D577CA
#define CLoadBalanceNodeHashFactory_H_HEADER_INCLUDED_B3D577CA

#include <string>
#include <map>
using namespace std;

#include "CLoadBalanceNodeHash.h"

namespace MyTENPAYAPI {

// ȫ�ֱ���
// map<string,CLoadBalanceNodeHash*(*)()> g_mCLoadBalanceNodeHashFactory;
// 
// ���ر������ù��캯������ӷ�����
// CLoadBalanceNodeHashFactory<T> g(inID);
// 
// �����κζ���ĳ�Ա��������ȡʵ��
// if(NULL!= g.GetInstance(inID))
//   g.DoSameThing();

// ȫ�ֱ���
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

    // ��ָ�����ֻ�ȡ��Ӧ��ǩ������
    //##ModelId=4C2AE6EF0307
    CLoadBalanceNodeHash* GetInstance(const std::string &inId)
    {
    		CLoadBalanceNodeHash * res = NULL;
    		
    		if(g_mCLoadBalanceNodeHashFactory.find(inId) != g_mCLoadBalanceNodeHashFactory.end())
    			res = g_mCLoadBalanceNodeHashFactory[inId]();
    		
    		return res ;
    	}


    // �����ض�����ķ���
    //##ModelId=4C2AE6EF0336
    static CLoadBalanceNodeHash* Method()
    {
      return (CLoadBalanceNodeHash *)(new T);
    }


};
extern CLoadBalanceNodeHashFactory<CLoadBalanceNodeHash> g_CLoadBalanceNodeHashFactory;
} // namespace MyTENPAYAPI



#endif /* CLoadBalanceNodeHashFactory_H_HEADER_INCLUDED_B3D577CA */
