#ifndef CLARGS_H
#define CLARGS_H

#include <vector>
#include <string>
#include <set>
#include <map>

namespace SDI
{
	std::vector<std::string> parseArgs(int argc, char * argv[]);
	std::set<char> parseArgsFlags(int argc, char * argv[]);
	std::map<char, std::string> parseArgsValues(int argc, char * argv[]);
}

#endif