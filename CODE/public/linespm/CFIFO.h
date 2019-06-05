#ifndef CFIFO_H_HEADER_INCLUDED_AFDF427E
#define CFIFO_H_HEADER_INCLUDED_AFDF427E

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <map>
#include <set>
#include <ostream>

using namespace std;

typedef struct ST_CFIFOHeader
{
	unsigned int m_uiRecordNumber;
	
	size_t	m_szOffsetOfRead;
	
	size_t	m_szOffsetOfWrite;

	size_t  m_szOffsetOfData;
	
}CFIFOHEader;

//##ModelId=5020CDE7017C
class CFIFO
{
  	inline void SequenceWrite(const char * src,unsigned int sz);
  	inline void SequenceRead(char * src,unsigned int sz);
	inline void SequenceRead(std::string &dst,unsigned int sz);
  public:
    // ��ʼ������
    // 0 �ɹ�
    // * ʧ��
    //##ModelId=5020CFD80069
    int Init(
        // ������ʼ��ַ
        char * io_pLineSpace, size_t in_szFIFO,bool in_ExistFlag=0);

    // 0 �ɹ�д��
    // * ʧ��
    //##ModelId=5020D17E016A
    int PushBack(const char *in_pszBuf, unsigned int in_uiSize);

    // ������������ó���
    //##ModelId=5020D1DC0333
    int RemoveTop(std::string &io_sRes);

    //##ModelId=5020D9990273
    CFIFO();

    //##ModelId=5020D99902A2
    virtual ~CFIFO();

	inline size_t GetUsedBufferSize()
	{
		size_t szRes = 0;
		
		if(m_pobjCFIFOHEader->m_szOffsetOfWrite >= m_pobjCFIFOHEader->m_szOffsetOfRead)
		{
			szRes = m_pobjCFIFOHEader->m_szOffsetOfWrite - m_pobjCFIFOHEader->m_szOffsetOfRead;
		}
		else
		{
			szRes = m_uiTotalSize - m_pobjCFIFOHEader->m_szOffsetOfRead - m_pobjCFIFOHEader->m_szOffsetOfData + m_pobjCFIFOHEader->m_szOffsetOfWrite;
		}

		return szRes;
	}

	void DumpMemInfo(std::ostream &os )
	{
		os << "StartAddress \t  TotalSize  \t ItemCount  \t  UsedSize   \t  Read Offset  \t  Write Offset  \t  Data Offset \r\n" 
			<< (void *)m_pStartAddress << " \t " 
			<< m_uiTotalSize << " \t " 
			<< m_pobjCFIFOHEader->m_uiRecordNumber << "  \t  "
			<< GetUsedBufferSize() 	<< " \t " 
			<< m_pobjCFIFOHEader->m_szOffsetOfRead  << " \t " 
			<< m_pobjCFIFOHEader->m_szOffsetOfWrite  << "  \t  " 
			<< m_pobjCFIFOHEader->m_szOffsetOfData
			<< "\n "<< std::endl;
	};

  private:
    // �ܳߴ�byte
    //##ModelId=5020CEB4021A
    size_t m_uiTotalSize;

    // ��ʼ��ַ
    //##ModelId=5020CEDE035C
    char *m_pStartAddress;

    CFIFOHEader * m_pobjCFIFOHEader;

};



#endif /* CFIFO_H_HEADER_INCLUDED_AFDF427E */

