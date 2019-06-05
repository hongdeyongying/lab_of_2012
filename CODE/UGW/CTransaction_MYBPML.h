// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CTRANSACTION_MYBPML_H_HEADER_INCLUDED_B3EE7263
#define CTRANSACTION_MYBPML_H_HEADER_INCLUDED_B3EE7263

#include "mysoft_cgi.h"

#include "CTransaction.h"

//#include <mysql++.h>

#include "CConfigEntry.h"

#include "CBaseEncode.h"

namespace MyAPP {

// 测试用的东东
//##ModelId=4C11B36A03D2
class CTransaction_MYBPML : public MyCGI::CTransaction
{
  private:

  public:
	CTransaction_MYBPML();
	virtual ~CTransaction_MYBPML();
  
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
		//配置文件
		MyConfig::CConfigEntry & config) throw(MyUtility::CMyException);
};

} // namespace MyAPP



#endif /* CTRANSACTION_MYBPML_H_HEADER_INCLUDED_B3EE7263 */
