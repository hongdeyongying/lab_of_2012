#include "CConvertorFactory.h"

#include "mysoft_cgi.h"

using namespace MyCGI;
using namespace MyUtility;

void testConvertFactory()
{
	cout << "\r\n*testConvertFactory" << endl;
	CConvertor * p = g_CConvertorFactory.GetInstance("base");
	
	string src("%20%%\\:&&x#<.>;");cout << src << endl;
	
	p->DoSingle(src,"urlencode");	cout << src << endl;
	p->DoSingle(src,"urldecode");	cout << src << endl;
	
	p->DoSingle(src,"xmldecode");	cout << src << endl;
	p->DoSingle(src,"xmlencode");	cout << src << endl;
	p->DoSingle(src,"xmldecode");	cout << src << endl;
}


int main(int argc,char ** argv)
{
	std::cout << __LINE__ << std::endl;

	testConvertFactory();
	
	std::cout << __LINE__ << std::endl;
}

