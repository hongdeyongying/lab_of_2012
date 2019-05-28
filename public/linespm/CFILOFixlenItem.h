#ifndef CFILOFIXLENITEM_H_HEADER_INCLUDED_AFDF635B
#define CFILOFIXLENITEM_H_HEADER_INCLUDED_AFDF635B

#include <iostream>
#include <string>

#include "ShareMemory_Errorcd.h"

// �Ƚ�������У������ڹ����ڴ���ʵ�ֿ��ٵĿ��п����
//##ModelId=5020B00D0191
template <class T>
class CFILOFixlenItem
{
  public:
  	void DumpMemInfo(std::ostream &os )
	{
		os << "StartAddress \t FirstItemAddress  \t  MaxItemCount  \t ItemCount  \t    FirstItemValue \r\n" 
			<< (void *)m_pStartAddress << " \t " 
			<< (void *)m_pFirstItemAddress << " \t " 
			<< *m_puiMaxItemCount << " \t " 
			<< *m_puiItemCount << "  \t  "
			<< (T)*m_pFirstItemAddress
			<< "\n "<< std::endl;
	};
    // ��ʼ��FILO���еĴ�С����¼����С
    // 
    // 0 ��ʼ���ɹ�
    // * ʧ��
    //##ModelId=5020B1D90307
    int Init(char * io_pLineSpace, size_t in_szLineSpace, bool in_Exist)
    {
		if(in_szLineSpace == 0)  return 0;	
		
		m_pStartAddress = io_pLineSpace;

		m_puiMaxItemCount = (unsigned int * )m_pStartAddress;

		m_puiItemCount = (unsigned int * )(m_pStartAddress + sizeof(unsigned int));

		m_pFirstItemAddress = m_pStartAddress + 2 * sizeof(unsigned int);

		if(in_Exist == 0)
		{
			*m_puiMaxItemCount = in_szLineSpace/sizeof(T);

			*m_puiItemCount = 0;
		}
		
		//io_pLineSpace += in_szLineSpace;

		return 0;

		
	};

    // �Ƴ���������е�item
    // 
    // 0 �ɹ�
    // * ʧ��
    //##ModelId=5020B4EE0091
    int Pop(T &o_objFixSize)
    {
    	if( *m_puiItemCount <= 0)
		{
			return SHM_FILO_NO_ITEM;
		}

		o_objFixSize = *(T *)(m_pFirstItemAddress + (--(*m_puiItemCount)) * sizeof(T));

		return 0;
    };

    // ������ѹ���������λ��
    //##ModelId=5020B5AB03C7
    int Push(T in_objFixSize)
    {
    	if(*m_puiItemCount >= *m_puiMaxItemCount)
    	{
    		return SHM_FILO_MAX_ITEM;
    	}

		*(T *)(m_pFirstItemAddress + ((*m_puiItemCount)++) * sizeof(T)) = in_objFixSize;

		return 0;
    };

	virtual ~CFILOFixlenItem(){};

	CFILOFixlenItem()
	{
		m_pStartAddress     = NULL;
		m_pFirstItemAddress = NULL;
	}

  private:
    //##ModelId=5020B60E02DB
    char *m_pStartAddress, *m_pFirstItemAddress;

    //##ModelId=5020B654023D
    unsigned int *m_puiMaxItemCount;

    //##ModelId=5020B6890052
    unsigned int *m_puiItemCount;

};



#endif /* CFILOFIXLENITEM_H_HEADER_INCLUDED_AFDF635B */
