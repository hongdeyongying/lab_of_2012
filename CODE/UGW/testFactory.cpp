#include "CConvertorFactory.h"
#include "CCheckerFactory.h"
#include "CTransactionFactory.h"
//#include "boost/exception/info.hpp"
//#include "boost/exception/error_info.hpp"
//#include "boost/exception/get_error_info.hpp"

//using namespace boost;

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

void testCTransactionFactory()
{

	cout << "\r\n*testCTransactionFactory" << endl;
	CTransaction * p = g_CTransactionFactory.GetInstance("test");
	
	CStringVectorMap in,out;
	
	p->Do(in,out);
	
	cout << out.GetFirst("retcode") << ":" << out.GetFirst("retmsg") << endl;
}

void testCheckerFactory()
{
	cout << "\r\n*testCheckerFactory" << endl;
	
	CChecker * p = g_CCheckerFactory.GetInstance("regex");
	
	string src("%20%%\\:&&x#<.>;");
	string reg("[.]+");
	
	cout << src << " : " << reg << endl;	cout << p->DoSingle(src,reg) << endl;
	
	src = "abce";
	reg = "[a-z]+";
	cout << src << " : " << reg << endl;	cout << p->DoSingle(src,reg) << endl;
}

#include <iostream>
#include <cassert>
#include <string>
#include "boost/regex.hpp"
void testRegex()
{
	// 3 digits, a word, any character, 2 digits or "N/A", 
	 // a space, then the first word again
	boost::regex reg("\\d{3}([a-zA-Z]+).(\\d{2}|N/A)\\s\\1");
	//
	std::string correct="123Hello N/A Hello";
	std::string incorrect="123Hello 12 hello";
	//
	assert(boost::regex_match(correct.c_str(),reg)==true);
	assert(boost::regex_match(incorrect.c_str(),reg)==false);	
}
#include <string>
#include <map>
#include <boost/regex.hpp>
void testRegex2()
{
	// purpose: 
	// takes the contents of a file in the form of a string 
	// and searches for all the C++ class definitions, storing 
	// their locations in a map of strings/int's 
	typedef std::map<std::string, int, std::less<std::string> > map_type;

	boost::regex expression(
	   "([$]{1})([a-zA-Z:_0-9]+)([$]{1})");

	map_type m;
	std::string file="$uid$bbbb";
	
	std::cout << __LINE__ << std::endl;
	
		   std::string::const_iterator start, end;
	   start = file.begin();
	   end = file.end();
		  boost::match_results<std::string::const_iterator> what;
	   boost::match_flag_type flags = boost::match_default;
	   
	   std::cout << __LINE__ << std::endl;
	   
	   bool re = false;
	
	try{
	   while(re = regex_search(start,end, what, expression, flags))
	   {
			std::cout << __LINE__ << " " << what.size() << std::endl;
		  // what[0] contains the whole string 
		  // what[5] contains the class name. 
		  // what[6] contains the template specialisation if any. 
		  // add class name and position to map: 
		 m[std::string(what[5].first, what[5].second)
				+ std::string(what[6].first, what[6].second)]
			 = what[5].first - file.begin();
		  // update search position: 
		  start = what[0].second;
		  // update flags: 
		  flags |= boost::match_prev_avail;
		  flags |= boost::match_not_bob;
	   }
	}
	catch(...)
	{
		//if( int const * e=boost::get_error_info<boost::errno_info>(expr) )
		std::cout << "*boost::get_error_info<errno_info>(e)" << std::endl;
	}
	
	
	std::cout << __LINE__ << " : " << re << std::endl;
	
	map_type::iterator iter = m.begin();
	for(;iter != m.end();iter++)
		std::cout << iter->first << " " << iter->second << std::endl;
	
	
}
int main(int argc,char ** argv)
{
	testConvertFactory();
	
	testCheckerFactory();
	
	testCTransactionFactory();

	testRegex();
	
	std::cout << __LINE__ << std::endl;
	testRegex2();
	std::cout << __LINE__ << std::endl;
}

