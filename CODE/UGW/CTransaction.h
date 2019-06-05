// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CTRANSACTION_H_HEADER_INCLUDED_B3EE21B4
#define CTRANSACTION_H_HEADER_INCLUDED_B3EE21B4

#include "mysoft_cgi.h"
#include "CConfigEntry.h"

#define ERROR_RETURN(retcd,retmsg,res) {res["retcode"].push_back(retcd);res["retmsg"].push_back(retmsg);return atoi(retcd);}

namespace MyCGI {

// 业务提交，所有新增业务必须从这里派生
//##ModelId=4C11B0C8023F
class CTransaction
{
  public:
  	CTransaction(){};
  	virtual ~CTransaction(){};
    // 提交交易，返回一个整数值。并抛出异常
    //##ModelId=4C11B0E100F7
    virtual int Do(
        // 输入参数
        const MyUtility::CStringVectorMap &inPara, 
        // 输出参数
        MyUtility::CStringVectorMap& outPara) throw(MyUtility::CMyException);
    virtual int Do(
        // 输入参数
        const MyUtility::CStringVectorMap &inPara, 
        //env
        const MyUtility::CStringMap &inEnv,
        //cookie
        const MyUtility::CStringMap &inCookie,
        //file
        const MyUtility::CStringVectorMap &inFileData, 
        // 输出参数
        MyUtility::CStringVectorMap& outPara,
        MyConfig::CConfigEntry & config) throw(MyUtility::CMyException);

};

} // namespace MyCGI



#endif /* CTRANSACTION_H_HEADER_INCLUDED_B3EE21B4 */
