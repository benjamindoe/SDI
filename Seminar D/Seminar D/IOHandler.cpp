#include <sstream>
#include <cassert>

#include "IOHandler.h"


IOHandler::IOHandler(std::string filename, std::ios_base::openmode mode)
{
	file.open(filename, mode);
}


IOHandler::~IOHandler()
{
	file.close();
}

std::vector<std::vector<std::string>> IOHandler::parseCsv()
{
	std::vector<std::vector<std::string>> parsedCsvElem;
	assert(file.is_open() && "Unable to open file.");
	std::string line;
	std::vector<std::string> tmpCsvElem;
	while (std::getline(file, line))
	{
		std::stringstream ss(line);
		while (std::getline(ss, line, ','))
		{
			tmpCsvElem.push_back(line);
		}
		parsedCsvElem.push_back(tmpCsvElem);
	}
	return parsedCsvElem;
}

void IOHandler::writeCsv(std::vector<std::string> dataToWrite)
{
	assert(file.is_open() && "Unable to open file.");
	for (std::vector<std::string>::iterator it = dataToWrite.begin(); it != dataToWrite.end(); it++)
	{
		file << *it;
	}
	//dataToWrite
}
