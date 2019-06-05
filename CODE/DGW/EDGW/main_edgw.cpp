/* 嵌入式设备接入网关，实现对业内热门的车载定位诊断设备的支持
 * gaoyong gycommunicate@163.com
 * 2013-07-29
 */
#include "CFrame.h"

int main (int argc,const char ** argv)
{		
	MyUtility::g_objCCommandLineInfo.AddEntry("CONFIG_FILE_PATH","-c","",false,false,"指定配置文件");
	
	MyUtility::g_objCCommandLineInfo.Parse(argc,argv);

	CFrame myFrame;

	return 0;
}
