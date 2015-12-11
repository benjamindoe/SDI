#ifndef SDI_CPP
#define SDI_CPP

#include "CLargs.h"

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
					std::string str(argv[i]);
					if (str.find('=') == std::string::npos) {
						for (int j = 1; j < str.length(); j++)
						{
							flags.insert(str[j]);
						}
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
				std::string str(argv[i]);
				if (str.length() > 1 && str[0] == '-' && str.find('=') != std::string::npos)
				{
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