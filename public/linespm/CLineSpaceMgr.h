#ifndef CLINESPACEMGR_H_HEADER_INCLUDED_AF09D4A4
#define CLINESPACEMGR_H_HEADER_INCLUDED_AF09D4A4

#include "ILineSpaceManager.h"

#include <sstream>

#include "CLineSpaceHeader.h"



//

#include <errno.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <stdio.h>
#include <sys/time.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

#include <sys/ipc.h>
#include <sys/shm.h>


#include "CLIFO.h"

//##ModelId=50EFD36001C0
class CLineSpaceMgr : public ILineSpaceManager
{
  private:
  	std::ostringstream m_sTraceMessage;

	
  	
  public:

	void DumpInfo(std::ostream &os);

	const std::string GetTraceLog() const {return m_sTraceMessage.str();};
    void  ClearTraceLog()  { m_sTraceMessage.str("");};
	
    
    //##ModelId=50EFDBF402A4 
    // inName Ψһ���һ���ڴ��,< 250 �ֽ�,һ��дһ������
    // ����shget����ʱ��ֻ��Ϊһ��8λ�������ַ������������һ���ڴ棬���庬�壬�����ļ�ָ��
    virtual int Init(
    // ����ߴ�
        size_t inObjSize, 
        // ���������
        size_t inMaxObjCount, 
        // ģ����_Line_objSize_inName
        const char *inName="",
        bool bMmap = true
     	);

	virtual int InitShmat(
		// ����ߴ�
        size_t inObjSize, 
        // ���������
        size_t inMaxObjCount, 
        // ģ����_Line_objSize_inName
        const char *inName = "88888888"
		);
    virtual int InitMmap(
        // ����ߴ�
        size_t inObjSize, 
        // ���������
        size_t inMaxObjCount, 
        // ģ����_Line_objSize_inName
        const char *inName = "");

    // ����һ������ռ䣬���ռ䲻��ʱ�������ʧ��
    //##ModelId=50EFDBF7037A
    virtual CPointer Alloc();

    //##ModelId=50EFDBF9006B
    virtual int Free(const CPointer &inPointer);

    // ת��ΪCָ�룬�ɽ�����Ӧ��ָ�����㣬����Խ��Ҫ�����߱�֤
    //##ModelId=50EFDBFA0318
    virtual void *AsVoid(const CPointer &inPointer);

    // ����ʵ�ʳɹ�����Ŀռ����������С����Ҫ�Ŀռ��������Ϊ0����ʾ�ռ䲻��
    //##ModelId=50EFDBFD0074
    virtual int Alloc(
        // ��Ҫ�Ŀɴ�Ŷ�������Ŀռ�
        size_t inObjCount, 
        // �������շ���ռ��ָ��
        CPointer* iopCPointer);

    // ����ʵ�ʳɹ��ͷŵĿռ����
    //##ModelId=50EFDBFE02E3
    virtual int Free(
        // ��Ҫ���ͷŵĿռ����
        size_t inObjCount, 
        // ���ı�����˳���ͷųɹ��Ŀռ�IsNullΪtrue
        CPointer* iopCPointer);

    // �鿴�Ƿ��п��пռ�
    //##ModelId=50EFDC0D0074
    bool IsFull();

    // ���ؿɷ���Ķ���ռ����
    //##ModelId=50EFE4E700ED
    unsigned int GetFreeSize();

    // �����ܵĶ���ռ����
    //##ModelId=50F619AB00B7
    unsigned int GetTotalSize();

    // ���ش�ŵĶ���ռ����
    //##ModelId=50F619C203BA
    unsigned int GetSize();

    //##ModelId=50F61BE60282
    virtual size_t GetObjSize();

    virtual size_t GetObjCount(){return GetTotalSize();};
    virtual size_t GetUsedCount(){return GetSize();}

    //##ModelId=50EFD5C30096
    CLineSpaceHeader * m_pobjCLineSpaceHeader;
	CLineSpaceTail * m_pobjCLineSpaceTail;
	
	const CLineSpaceTail m_objCLineSpaceTail;
	CLineSpaceHeader m_objCLineSpaceHeader;

	CLineSpaceMgr(){m_bInitOK = false; m_szObjSize=0; m_uiID = 1;};
	~CLineSpaceMgr(){};

  private:
    //##ModelId=50EFDACD03E7
    unsigned int m_uiID;

    //##ModelId=50EFDADE01BB
    std::string m_sName;

    //##ModelId=50EFE47D03B3
    char  *m_pStartAddress;

    //##ModelId=50EFD83C006D
    CLIFO<unsigned int> m_objCLIFOFree;

	// ����ߴ�
	size_t m_szObjSize;	
	size_t m_szObjSizeOrg;	


	char * m_pFirstObjAddress;

	
	bool m_bInitOK;

	// shmget base info
	// �����ڴ�Ļ�����Ϣ��̬
	int m_iShareMemoryID;				// �����ڴ��Ǻ�
	struct shmid_ds m_objShmidDs;		// �����ڴ������

};



#endif /* CLINESPACEMGR_H_HEADER_INCLUDED_AF09D4A4 */
