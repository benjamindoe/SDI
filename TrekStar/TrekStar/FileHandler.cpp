#ifndef FILEHANDLER_CPP
#define FILEHANDLER_CPP

#include <sstream>
#include <cassert>

#include "FileHandler.h"

using json = nlohmann::json;

FileHandler::FileHandler(std::string filename)
{
	filename_ = filename;
}


FileHandler::~FileHandler()
{
}

json FileHandler::parseJson()
{
	std::ifstream file(filename_);
	;
	std::string fileContent((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	const char* jsonBuffer = fileContent.c_str();
	file.close();
	return json::parse(jsonBuffer);
}

void FileHandler::writeJson(json jsonData)
{
	std::ofstream file(filename_);
	file << std::setw(2) << jsonData;
	file.close();
}
/*
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
*/
#endif // !FILEHANDLER_CPP
