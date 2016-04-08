#include <sstream>
#include <cassert>

#include "FileHandler.h"


FileHandler::FileHandler(std::string filename, std::ios_base::openmode mode)
{
	file.open(filename, mode);
}


FileHandler::~FileHandler()
{
	file.close();
}

JSONValue* FileHandler::parseJson()
{
	std::string fileContent((std::istreambuf_iterator<char>(file)), (std::istreambuf_iterator<char>()));
	const char* jsonBuffer = fileContent.c_str();

	return JSON::Parse(jsonBuffer);
}

void FileHandler::writeJson(JSONObject jsonData)
{
	JSONValue* jsonVal = new JSONValue(jsonData);
	file << jsonVal->Stringify().c_str();
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
