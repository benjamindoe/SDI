#ifndef FILEHANDLER_CPP
#define FILEHANDLER_CPP

#include <sstream>
#include <cassert>

#include "FileHandler.h"

using json = nlohmann::json;

FileHandler::FileHandler(std::string filename, std::ios_base::openmode mode)
{
	file.open(filename, mode);
}


FileHandler::~FileHandler()
{
	file.close();
}

json FileHandler::parseJson()
{
	std::string fileContent((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	const char* jsonBuffer = fileContent.c_str();

	return json::parse(jsonBuffer);
}

void FileHandler::writeJson(json jsonData)
{
	file << jsonData;
}

std::vector<std::vector<std::string>> FileHandler::parseCsv()
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

void FileHandler::writeCsv(std::vector<std::string> dataToWrite)
{
	assert(file.is_open() && "Unable to open file.");
	for (std::vector<std::string>::iterator it = dataToWrite.begin(); it != dataToWrite.end(); it++)
	{
		file << *it;
	}
	//dataToWrite
}

#endif // !FILEHANDLER_CPP
