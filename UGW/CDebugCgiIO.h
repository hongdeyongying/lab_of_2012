#include "CCgiIO.h"
// *************************************************
// 创建日期： 2010-5-14                      
// 作    者：高勇 (gaussgao@tencent.com)
// 主要功能： 实现C++的cgi框架，以简化CGI的编程。  
// *************************************************

#ifndef CDEBUGCGIIO_H_HEADER_INCLUDED_B3EE546D
#define CDEBUGCGIIO_H_HEADER_INCLUDED_B3EE546D

#include "mysoft_cgi.h"

namespace MyCGI {

//##ModelId=4C0C710D0030
class CDebugCgiIO : public CCgiIO
{
  public:
    //##ModelId=4C11D6B20196
    virtual size_t read(char *outDat, size_t inLen);

    //##ModelId=4C11D6B20199
    virtual std::string getenv(const char *inName);

    //##ModelId=4C11D6B80177
    virtual std::string getenv(const std::string &inName);

    //##ModelId=4C11D725003E
    CDebugCgiIO(const std::string &inFile,const std::string &inRequest);

    //##ModelId=4C11D725006D
    virtual ~CDebugCgiIO();
//protected:
//	MyUtility::CStringMap 	m_mEnv;

private:
	void ReadFile(const std::string & inFileName)
	{
		FILE *stream;
		if( (stream  = fopen( inFileName.c_str(), "rb" )) == NULL )
			return ;
		
		fseek(stream,0,SEEK_END);
		
		LONG fLength = ftell(stream);

		fseek(stream,0,SEEK_SET);

		int actReadCount = 0;
		
		char c;

		for(LONG i=0;i<fLength;i++)
		{
			actReadCount = fread( &c, sizeof( char ), 1, stream );

			if(actReadCount != 1)
				break;

			m_sIn.append(1,c);
			
		}


		/* Close stream */
		fclose( stream ) ;

	}
	
	std::string m_sIn;
	std::string::const_iterator m_sInIter;
	

};

} // namespace MyCGI



#endif /* CDEBUGCGIIO_H_HEADER_INCLUDED_B3EE546D */
