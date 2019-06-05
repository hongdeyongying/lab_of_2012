// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CCONVERTORFACTORY_H_HEADER_INCLUDED_B3E0FEF2
#define CCONVERTORFACTORY_H_HEADER_INCLUDED_B3E0FEF2

#include "mysoft_cgi.h"

#include "CConvertor.h"

namespace MyCGI {

// ȫ�ֱ���
extern map<string,CConvertor*(*)()> g_mCConvertorFactory;
extern map<string,CConvertor*> g_mCConvertor;
// 
// ���ر������ù��캯������ӷ�����
// CConvertorFactory<T> a(inID);
// 
// �����κζ���ĳ�Ա��������ȡʵ��
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
    // ��ָ�����ֻ�ȡ��Ӧ��ת������
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


    // �����ض�����ķ���
    //##ModelId=4C1F071502C9
    static CConvertor *Method()
    {
      return (CConvertor *)(new T);
    }


};


extern CConvertorFactory<CConvertor> g_CConvertorFactory;
} // namespace MyCGI



#endif /* CCONVERTORFACTORY_H_HEADER_INCLUDED_B3E0FEF2 */
