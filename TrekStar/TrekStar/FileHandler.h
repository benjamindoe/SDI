#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include <fstream>

#include "JSON\JSON.hpp"
using json = nlohmann::json;
/*
 * JSON parser I am using.
 * https://github.com/nlohmann/json
 */
class FileHandler
{
public:
	FileHandler(std::string filename);
	~FileHandler();
	json parseJson();
	void writeJson(json jsonData);
private:
	void writeCsv(std::vector<std::string> dataToWrite);
	std::vector<std::vector<std::string>> parseCsv();
	std::string filename_;
};

#endif //FILEHANDLER_H