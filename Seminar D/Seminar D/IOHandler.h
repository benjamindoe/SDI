#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include <fstream>

#include "JSON/JSON.h"
/*
 * JSON parser I am using.
 * https://github.com/MJPA/SimpleJSON/blob/master/src/demo/example.cpp
 */
class IOHandler
{
public:
	IOHandler(std::string filename, std::ios_base::openmode mode = std::ofstream::trunc);
	~IOHandler();
	std::vector<std::vector<std::string>> parseCsv();
	void writeCsv(std::vector<std::string> dataToWrite);
private:
	std::fstream file;
};

#endif //FILEHANDLER_H