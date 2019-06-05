#include "CDigitalSignature.h"
// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CDIGITALSIGNATUREFACTORY_H_HEADER_INCLUDED_B3D577CA
#define CDIGITALSIGNATUREFACTORY_H_HEADER_INCLUDED_B3D577CA

#include "mysoft_cgi.h"

#include "CDigitalSignature.h"

namespace MyCGI {

// ȫ�ֱ���
// map<string,CDigitalSignature*(*)()> g_mCDigitalSignatureFactory;
// 
// ���ر������ù��캯������ӷ�����
// CDigitalSignatureFactory<T> g(inID);
// 
// �����κζ���ĳ�Ա��������ȡʵ��
// if(NULL!= g.GetInstance(inID))
//   g.DoSameThing();

// ȫ�ֱ���
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

    // ��ָ�����ֻ�ȡ��Ӧ��ǩ������
    //##ModelId=4C2AE6EF0307
    MyCGI::CDigitalSignature* GetInstance(const std::string &inId)
    {
    		CDigitalSignature * res = NULL;
    		
    		if(g_mCDigitalSignatureFactory.find(inId) != g_mCDigitalSignatureFactory.end())
    			res = g_mCDigitalSignatureFactory[inId]();
    		
    		return res ;
    	}


    // �����ض�����ķ���
    //##ModelId=4C2AE6EF0336
    static MyCGI::CDigitalSignature* Method()
    {
      return (CDigitalSignature *)(new T);
    }


};
extern CDigitalSignatureFactory<CDigitalSignature> g_CDigitalSignatureFactory;
} // namespace MyCGI



#endif /* CDIGITALSIGNATUREFACTORY_H_HEADER_INCLUDED_B3D577CA */
