#ifndef CLINESPACEHEADER_H_HEADER_INCLUDED_AF099284
#define CLINESPACEHEADER_H_HEADER_INCLUDED_AF099284

#pragma pack(1)

#include <string.h>


//##ModelId=50EFC0170076
typedef struct ST_CLineSpaceHeader
{
    // һ��line��ַ�ռ�Ĵ�С���ֽ��� = m_uiLineSpaceSize * 8 byte
    //##ModelId=50EFC0C601FE
    unsigned int m_uiSize;

    // �Ѿ�ʹ�õĳߴ磬��λ 8 �ֽ�
    //##ModelId=50EFC1E402E6
    unsigned int m_uiUsed;

    // ���󳤶ȣ���λ 8 �ֽ�
    //##ModelId=50EFC2380108
    unsigned int m_uiObjSize;
	unsigned int m_uiObjSizeOrg;

    // ���Ե�ַ���ֳ���
    //##ModelId=50EFC28202FE
    unsigned char m_ubNameLen;

    //##ModelId=50EFC2B60025
    char m_strName[1];

	ST_CLineSpaceHeader()
	{
		m_uiSize = m_uiUsed = m_uiObjSize = m_ubNameLen = 0;
	}

}CLineSpaceHeader;

typedef struct ST_CLineSpaceTail
{
	unsigned char m_ubSplit;   	// 0x00
	char m_szEnd[3];			// "END"

	ST_CLineSpaceTail()
	{
		m_ubSplit = 0;
		m_szEnd[0]='E';
		m_szEnd[1]='N';
		m_szEnd[2]='D';
	}

	int operator==(const ST_CLineSpaceTail& right)
	{
		return (m_ubSplit == right.m_ubSplit ) && (memcmp(m_szEnd,right.m_szEnd,3)== 0);
	}
	
}CLineSpaceTail;


#pragma pack() 



#endif /* CLINESPACEHEADER_H_HEADER_INCLUDED_AF099284 */
