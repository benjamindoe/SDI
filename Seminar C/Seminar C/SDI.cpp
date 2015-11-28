#ifndef SDI_CPP
#define SDI

#include "SDI.h"

namespace SDI
{
	std::vector<std::string> parseArgs(int argc, char * argv[])
	{
		std::vector<std::string> strings;
		if (argc > 1)
		{
			strings.reserve(argc - 1);
			for (int i = 1; i < argc; i++)
			{
				strings.push_back(std::string(argv[i]));
			}
		}
		return strings;
	}
	std::set<char> parseArgsFlags(int argc, char * argv[])
	{
		std::set<char> flags;
		if (argc > 1)
		{
			for (int i = 1; i < argc; i++)
			{
				if (strlen(argv[i]) > 1 && argv[i][0] == '-' || argv[i][0] == ' / ' )
				{
					for (int j = 1; j < strlen(argv[i]); j++)
					{
						flags.insert(argv[i][j]);
					}
				}
			}
		}
		return flags;
	}
	std::map<char, std::string> parseArgsValues(int argc, char * argv[])
	{
		std::map<char, std::string> flagValues;

		if (argc > 1)
		{
			for (int i = 1; i < argc; i++)
			{
				if (strlen(argv[i]) > 1 && argv[i][0] == '-')
				{
					std::string str(argv[i]);
					std::size_t pos = str.find('=');
					std::string argVal = str.substr(pos + 1);
					flagValues.insert( std::pair<char, std::string>(argv[i][1], argVal) );
				}
			}
		}

		return flagValues;
	}
}

#endif