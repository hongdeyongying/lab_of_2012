// *************************************************
// �������ڣ� 2010-5-14                      
// ��    �ߣ����� (gaussgao@tencent.com)
// ��Ҫ���ܣ� ʵ�ֻ�����ʽת����֧��HTTP�Ľ�����ת����  
// *************************************************

#ifndef CCOMMANDLINEINFO_H_HEADER_INCLUDED_B3F342F2
#define CCOMMANDLINEINFO_H_HEADER_INCLUDED_B3F342F2

#include "mysoft_utility.h"

#include "CStringMap.h"
#include "CStringVectorMap.h"


namespace MyUtility {

// �����еĳ�����ʽ��
// 1. program -f c:\test.ini
// 2. program -fc:\test.ini
// 3. program --file=c:\test.ini
// 4. program --debug --file=c:\test.ini 
// 5. program --debug --file="html c:\abc.txt"
// 6. program /f c:\test.ini
// 7. program /fc:\test.ini
// 
// �������ܹ�֧�ֲ���ȷ�ı�������
//##ModelId=4BFE305101CD
class CCommandLineInfo
{
  public:
    // ���Ӳ���ѡ��
    // 
    // name,default��alias,name
    // 
    // name
    //##ModelId=4C0CA4C903C8
    void AddEntry(
        // ����������
        const std::string &inName, const std::string &inAlias, const std::string &inDefault = "", bool inSingle=false,
        // Ĭ�ϲ����� ֻ����һ��������Ľ�����ǰ���
        bool inFlag = false,const std::string &inDesc = "");

    // ���AddEntry���ӵĲ�������
    //##ModelId=4C0CAF4D0156
    void Clear();

    // ���ղ���������ȡ��ֵ
    //##ModelId=4C0CAF7601C5
    const std::string GetArgVal(const std::string &inName);

    //##ModelId=4C0CB0D502FC
    int GetArgSize(const std::string &inName);

    //##ModelId=4C0CB10400BC
    const std::string GetArgVal(const std::string &inName, int inIndex);
    const std::string &GetCmdLine();
	const std::string &GetExePath();
	const std::string &GetExeName();
	
	const std::string &GetBinDir();
	const std::string &GetCnfDir();
	const std::string &GetLogDir();
	const std::string &GetTmpDir();
	const std::string &GetLibDir();
	const std::string &GetDatDir();
	
    //##ModelId=4C0CB2BA0280
    int Parse(int argc, const char ** argv);
	
	std::string GetPrompt();


    //##ModelId=4C0CB2FD007F
    CCommandLineInfo();

  
    //##ModelId=4C0CB2FD00AD
    virtual ~CCommandLineInfo();

  private:
     // 0 δ�ҵ�����
    // 1 ���ҵ�����
    // 2 �ҵ����ֺ�ֵ
    //##ModelId=4C0CBCF502DE
    int MatchName(const std::string &inDat, std::string & outName, std::string & outValue);
	
	void AddValue(const std::string & outName, const std::string & outValue);
	
    // ���� ��������Ӧ��ϵ
    //##ModelId=4C0CB00902A6
    CStringMap m_mAlias2Name;

    // ��ȱʡֵ�Ĳ���
    //##ModelId=4C0CB0280017
    CStringMap m_mName2Default;
    CStringMap m_mName2Desc;

    // Ĭ�ϵĲ���
    //##ModelId=4C0CB0330160
    std::string  m_sDefaultName;
	
	std::string  m_sExec,m_sTmpDir,m_sBinDir,m_sLogDir,m_sDatDir,m_sLibDir,m_sCnfDir,m_sExePath,m_sExeName;
	
	
	std::map <std::string,int>m_mNameSingle;

    // ������ֵ��ϵ
    //##ModelId=4C0CB09A024E
    CStringVectorMap m_mvNameVal;

};

extern  CCommandLineInfo g_objCCommandLineInfo;
} // namespace MyUtility



#endif /* CCOMMANDLINEINFO_H_HEADER_INCLUDED_B3F342F2 */
