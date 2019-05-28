#ifndef STLASTDEVICEDATA_H_HEADER_INCLUDED_AE04F8F8
#define STLASTDEVICEDATA_H_HEADER_INCLUDED_AE04F8F8
#include <sys/types.h>
#include <stdint.h>

#include <string>
#include <ostream>

#pragma pack(1)

//##ModelId=51FA15370236
typedef struct ST_LAST_DEVICE_DATA
{
    // ���������,���������豸��������ʱ�����豸��ɻ���
    //##ModelId=51FA35750286
    void Clear();

    //##ModelId=51FA15B30010
    uint32_t m_uiLatitude;

    //##ModelId=51FA27740326
    uint32_t m_uiLongitue;

    //##ModelId=51FA28900005
    uint16_t m_usLAC;

    //##ModelId=51FA28D80235
    uint64_t m_ullIMEI;

    //##ModelId=51FA29180340
    uint16_t m_usVno;

    //##ModelId=51FA294600F7
    uint16_t m_usDirection;

    //##ModelId=51FA295902D4
    uint8_t m_ubSpeed;

    //##ModelId=51FA29AB0052
    uint8_t m_ubMNC;

    //##ModelId=51FA29BF01B3
    uint16_t m_usCellID;

    // ���ҵ���
    // ��һ�ֽ� GPS״̬
    // 0 GPS �Ƿ�λ
    // 1 ��γ
    // 2 ����
    // 
    
    // 
    // �����ֽ� 0��2���ĸ�bit��ʾ��λ״̬
    // 16+ 0, ��λ��Ϣ��Ч���� 1
    // 16+ 1, 
    // 16+ 2, ��λ0x0f 0x3
    // 16+ 3, 

	
    //##ModelId=51FA29F80324
    uint32_t m_uiStatus;

    // ���һ��GPS�����ϱ�ʱ��
    //##ModelId=51FA279B017B
    uint32_t m_tmGpsData;

    // Խ�󣬱�ʾ����Խ��
    // 
    // 0���͵�ػ���
    // 1�����������Դ�绰�����ŵȣ�
    // 2���͵籨����
    // 3���͵磬������ʹ�ã�
    // 3~6����������ʹ�ã�ֻ�����ݵ������ٲ�ͬ�����С�
    //##ModelId=51FA2AA50084
    uint8_t m_ubPower;

    // Խ�󣬱�ʾGSM�ź�Խ��
    // 0x00�����źţ�
    // 0x01���źż���
    // 0x02���źŽ���
    // 0x03���ź�����
    // 0x04���ź�ǿ
    //##ModelId=51FA2B150099
    uint8_t m_ubGsm;

    // GPS��λ��״̬
    // 
    // 0 δ��λ
    // 1 ʵʱ
    // 2 ���
    //##ModelId=51FA2B8D01C5
    uint8_t m_ubGpsStatus;

    // GPS��λ����������
    //##ModelId=51FA2C0E03B4
    uint8_t m_ubSNumber;

    // GPS��λ��ǰ10�����������
    //##ModelId=51FA2C5F006C
    uint8_t m_ubSSNR[10];

    // ���һ�����������ϱ�ʱ��
    //##ModelId=51FA2CAC01A0
    uint32_t m_tmHBData;

    // ���ն˷��͵�ַ��ѯ������ֻ�����
    // 
    // ��ʾ22λ���֣��Ҷ��롣,��һλ�Ǳ�ʾӢ�ģ�����
    //##ModelId=51FA2D750332
    uint8_t m_ubMobile[11];
	

    // ���һ��λ�ò�ѯʱ��
    //##ModelId=51FA2E1B0197
    uint32_t m_tmAddrData;

    // ���һ���쳣ʱ��
    //##ModelId=51FA2EBD026D
    //�豸�쳣״̬
    //   1��10������GPS ���������,��
    //   2��GPS 10������û����λ��������
    //   3���豸���Ӳ��Ϸ�����������������
    //   4��SENSOR�Ĵ������ݸ�λ���³�ʼ����
    //   5��IMEI��ʧ������дimei���豸��
    //   6��24Сʱ�����豸.
    uint8_t m_ubExp;
    uint32_t m_tmExpData;

    // �豸��Ψһ��ʶ
    //##ModelId=51FA2FC303DA
    uint32_t m_uiDid;

	
	//
	uint32_t m_tmSvr;
	uint32_t m_tmTerm;

	//�豸��ͨѶ�ŵ�: ���豸��������ʱ���ͻᱣ�����ͨ�� 
	int 	m_sockDev;
	//�û���ͨѶ�ŵ�: ���û��鿴�豸����ϣ��ʵʱ�յ��豸��Ϣʱ���ͻᱣ������ͨ��
	int		m_sockUsr;
	
	std::string Hex(const uint8_t *ascii,int len)
	{
		std::string res("");
		
		const char *tbl="0123456789ABCDEF";
		unsigned char t;
		for(int i=0;i<len;i++)
		{
			t=(ascii[i]&(0xf0));
			t=t>>4;
			res +=*(tbl+t);
			
			t=(ascii[i]&(0x0f));

			res+=*(tbl+t);		
		}	
		return res;
	};


	template <class T>
	std::string Hex(const T & in)
		{
			return Hex((const uint8_t *)&in,sizeof(in));
		}

	void DumpInfo(std::ostream & os)
	{
		os << "\r\n---" << Hex( m_uiDid ) << " " << Hex( m_ullIMEI ) << "---" << std::endl;
		os << "+lati \t longi \t LAC \t Vno \t Dir \t Speed \t MNC \t CellID \t Status \t GpsDataTimeStamp \r\n"		
			<< Hex( m_uiLatitude ) << " " 
			<< Hex( m_uiLongitue ) << " "
			<< Hex( m_usLAC ) << " "
			<< Hex( m_usVno ) << " "
			<< Hex( m_usDirection ) << " "
			<< Hex( m_ubSpeed ) << " "
			<< Hex( m_ubMNC ) << " "
			<< Hex( m_usCellID ) << " "
			<< Hex( m_uiStatus ) << " "
			<< Hex( m_tmGpsData ) << std::endl;
			
		os << "+power \t gsm \t SNum \t SSNR \t HBDataTimeStamp \r\n"
			<< Hex( m_ubPower ) << " "
			<< Hex( m_ubGsm ) << " "
			<< Hex( m_ubGpsStatus ) << " "
			<< Hex( m_ubSNumber ) << " " 
			<< Hex( m_ubSSNR,10 ) << " "
			<< Hex( m_tmHBData ) << std::endl;
		
		os << "Mobile[11] = " << Hex( m_ubMobile,11 ) << " "  
		 	<< "AddrDataTimeStamp = " << Hex( m_tmAddrData ) << " "
			<< "Exp = " << Hex( m_ubExp ) << " "
			<< "ExpDataTimeStamp = " << Hex( m_tmExpData ) << std::endl;

		os << " ---dev sock " << m_sockDev << " ---- usr sock " << m_sockUsr  << "----\r\n\r\n"; 

		
	}
	

}StLastDeviceData;

#pragma pack()


#endif /* STLASTDEVICEDATA_H_HEADER_INCLUDED_AE04F8F8 */
