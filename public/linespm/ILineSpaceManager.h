#ifndef ILINESPACEMANAGER_H_HEADER_INCLUDED_AF099711
#define ILINESPACEMANAGER_H_HEADER_INCLUDED_AF099711
#include "CPointer.h"

//##ModelId=50EFD6130088
class ILineSpaceManager
{
  public:
    // ����һ������ռ䣬���ռ䲻��ʱ�������ʧ��
    //##ModelId=50EFD6F002C7
    virtual CPointer Alloc() = 0;

    //##ModelId=50EFD6F002C8
    virtual int Free(const CPointer &inPointer) = 0;

    // ת��ΪCָ�룬�ɽ�����Ӧ��ָ�����㣬����Խ��Ҫ�����߱�֤
    //##ModelId=50EFD6F002CA
    virtual void *AsVoid(const CPointer &inPointer) = 0;

    //##ModelId=50EFD6F002D7
    virtual int Init(
        // ����ߴ�
        size_t inObjSize, 
        // ���������
        size_t inMaxObjCount, 
        // ģ����_Line_objSize_inName
        const char *inName = "",bool isMmap=true) = 0;

    // ����ʵ�ʳɹ�����Ŀռ����������С����Ҫ�Ŀռ��������Ϊ0����ʾ�ռ䲻��
    //##ModelId=50EFD6F002DC
    virtual int Alloc(
        // ��Ҫ�Ŀɴ�Ŷ�������Ŀռ�
        size_t inObjCount, 
        // �������շ���ռ��ָ��
        CPointer* iopCPointer) = 0;

    // ����ʵ�ʳɹ��ͷŵĿռ����
    //##ModelId=50EFD6F002E6
    virtual int Free(
        // ��Ҫ���ͷŵĿռ����
        size_t inObjCount, 
        // ���ı�����˳���ͷųɹ��Ŀռ�IsNullΪtrue
        CPointer* iopCPointer) = 0;

    virtual size_t GetObjSize() = 0;
    virtual size_t GetObjCount() = 0;
    virtual size_t GetUsedCount() = 0;
};



#endif /* ILINESPACEMANAGER_H_HEADER_INCLUDED_AF099711 */
