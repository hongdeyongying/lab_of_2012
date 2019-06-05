// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ��C++��cgi��ܣ��Լ�CGI�ı�̡�  
// *************************************************

#ifndef CDatabaseHashFactory_H_HEADER_INCLUDED_B3D577CA
#define CDatabaseHashFactory_H_HEADER_INCLUDED_B3D577CA

#include "mysoft_app.h"

#include "CDatabaseHash.h"

namespace MyAPP {

// ȫ�ֱ���
// map<string,CDatabaseHash*(*)()> g_mCDatabaseHashFactory;
// 
// ���ر������ù��캯������ӷ�����
// CDatabaseHashFactory<T> g(inID);
// 
// �����κζ���ĳ�Ա��������ȡʵ��
// if(NULL!= g.GetInstance(inID))
//   g.DoSameThing();

// ȫ�ֱ���
extern map<std::string,CDatabaseHash*(*)()> g_mCDatabaseHashFactory;
extern map<std::string,CDatabaseHash*> g_mCDatabaseHash;


//##ModelId=4C2AE66E0353
template <typename T>
class CDatabaseHashFactory
{
  public:
    CDatabaseHash* GetSingletonInstance(const std::string &inId)
    {
    		CDatabaseHash * res = NULL;
			
			std::map<std::string,MyAPP::CDatabaseHash*>::iterator iter = g_mCDatabaseHash.find(inId);
			
			if((iter == g_mCDatabaseHash.end())||(iter->second == NULL))
			{
				if(g_mCDatabaseHashFactory.find(inId) != g_mCDatabaseHashFactory.end())
				{	
						res = g_mCDatabaseHash[inId] = g_mCDatabaseHashFactory[inId]();
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
    CDatabaseHashFactory(const std::string & inId)
    {
    //std::cout << __FILE__ << ":" << __LINE__ << inId << endl;		
		/*g_mCCheckerFactory[inId]=CCheckerFactory<T>::Method;*/
		
		std::map<std::string,CDatabaseHash*(*)()>::iterator iter ;

		iter = g_mCDatabaseHashFactory.find(inId);

		if(iter != g_mCDatabaseHashFactory.end())
		{
			iter->second = CDatabaseHashFactory<T>::Method;
		}
		else
		{
			g_mCDatabaseHashFactory.insert(map<string,CDatabaseHash*(*)()>::value_type(inId,CDatabaseHashFactory<T>::Method));
		}
	
		//std::cout << __FILE__ << ":" << __LINE__ << inId << endl;
    }

    //##ModelId=4C2AE6E30393
    virtual ~CDatabaseHashFactory()
    {
		std::map<std::string,MyAPP::CDatabaseHash*>::iterator iter ;
	
		for( iter = g_mCDatabaseHash.begin(); iter != g_mCDatabaseHash.end(); iter++)
		{
			if(NULL != iter->second)
			{
				delete iter->second;
				iter->second = NULL;
			}
		}
		
		g_mCDatabaseHash.clear();
		//g_mCDatabaseHashFactory.clear();
    };

    // ��ָ�����ֻ�ȡ��Ӧ��ǩ������
    //##ModelId=4C2AE6EF0307
    CDatabaseHash* GetInstance(const std::string &inId)
    {
    		CDatabaseHash * res = NULL;
    		
    		if(g_mCDatabaseHashFactory.find(inId) != g_mCDatabaseHashFactory.end())
    			res = g_mCDatabaseHashFactory[inId]();
    		
    		return res ;
    	}


    // �����ض�����ķ���
    //##ModelId=4C2AE6EF0336
    static CDatabaseHash* Method()
    {
      return (CDatabaseHash *)(new T);
    }


};
extern CDatabaseHashFactory<CDatabaseHash> g_CDatabaseHashFactory;
} // namespace MyAPP



#endif /* CDatabaseHashFactory_H_HEADER_INCLUDED_B3D577CA */
