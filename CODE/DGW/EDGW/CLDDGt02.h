#ifndef CLDDGT02_H_HEADER_INCLUDED_AE04E7A8
#define CLDDGT02_H_HEADER_INCLUDED_AE04E7A8
#include "ILastDeviceData.h"
#include "gt02.h"
#include "StLastDeviceData.h"

#include "CLineSpaceMgr.h"



#include "CPDDGt02.h"


#include <map>

//##ModelId=51FA37690121
class CLDDGt02 : public ILastDeviceData
{
	std::map<uint64_t,uint32_t> m_mIMEI2DID;
	unsigned int m_uiLastLoaded;

	bool m_bInit;
	CLineSpaceMgr objCLineSpaceMgr;
  public:
  	CLDDGt02(){m_bInit=false;}
    // <0 û���㹻�Ŀռ�������豸
    // 
    // 0  ��ȡ�ɹ�����Ϊ����ע����豸���ɴӽṹ��m_uiDid��ȡ�豸�ڲ�id
    // 
    // 1  ��ȡ�ɹ������Ѿ�ע������豸
    // 
    //##ModelId=51FB1A5502F7
    virtual int Register(uint64_t imei, StLastDeviceData* &data);

    // *  δע����豸
    // 
    // 0  ��ȡ�ɹ������Ѿ�ע������豸
    // 
    //##ModelId=51FB1A550307
    virtual int GetByImei(uint64_t imei, StLastDeviceData* &data);

    // *  �����洢�ռ䣬��DID���ڱ��洢����
    // 
    // 0  ��ȡ�ɹ�
    // 
    //##ModelId=51FB1A55030A
    virtual int GetByDID(uint32_t dir, StLastDeviceData* &data);


	// 0 �ɹ�
	// * ʧ��
	virtual int SetData(const StGt02TermToSvrMsg *pGt02Data,int sock=-1);

	// ��ʼ���洢�ռ䣬����������
	// 0 �ɹ�
	// * ʧ��
	int Init(int inDeviceNumber=10000,int inSplitPara_FromNumber = 0,const char * inName="LDD_GT02");

	void DumpInfo(std::ostream & os);

	void LoadChange();
	

};



#endif /* CLDDGT02_H_HEADER_INCLUDED_AE04E7A8 */
