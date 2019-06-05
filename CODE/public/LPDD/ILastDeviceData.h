#ifndef ILASTDEVICEDATA_H_HEADER_INCLUDED_AE04E1FB
#define ILASTDEVICEDATA_H_HEADER_INCLUDED_AE04E1FB
#include "StLastDeviceData.h"

//##ModelId=51FA22C40133
class ILastDeviceData
{
  public:
  	
  	//
  	uint32_t m_uiFromDid;
    // <0 û���㹻�Ŀռ�������豸
    // 
    // 0  ��ȡ�ɹ�����Ϊ����ע����豸���ɴӽṹ��m_uiDid��ȡ�豸�ڲ�id
    // 
    // 1  ��ȡ�ɹ������Ѿ�ע������豸
    // 
    //##ModelId=51FA268B0244
    virtual int Register(uint64_t imei, StLastDeviceData* &data) = 0;

    // *  δע����豸
    // 
    // 0  ��ȡ�ɹ������Ѿ�ע������豸
    // 
    //##ModelId=51FA36B202C4
    virtual int GetByImei(uint64_t imei, StLastDeviceData* &data) = 0;

    // *  �����洢�ռ䣬��DID���ڱ��洢����
    // 
    // 0  ��ȡ�ɹ�
    // 
    //##ModelId=51FA36FE0168
    virtual int GetByDID(uint32_t did, StLastDeviceData* &data) = 0;

};



#endif /* ILASTDEVICEDATA_H_HEADER_INCLUDED_AE04E1FB */
