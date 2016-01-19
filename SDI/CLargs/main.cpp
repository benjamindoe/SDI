
#include <iostream>
#include "CLargs.h"

using namespace std;

int main(int argc, char * argv[])
{
	SDI::parseArgs(argc, argv);
	std::set<char> myset = SDI::parseArgsFlags(argc, argv);
	map<char, string> mymap = SDI::parseArgsValues(argc, argv);
	set<char>::iterator it;
	for (it = myset.begin(); it != myset.end(); it++) {
		cout<<(*it)<<endl;
	}
	map<char, string>::iterator iter;
	for (iter = mymap.begin(); iter != mymap.end(); iter++)
	{
		cout << "Key: " << iter->first << endl << "Values: " << iter->second << endl;
	}
	return 0;
}

