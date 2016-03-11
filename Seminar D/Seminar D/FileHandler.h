#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <vector>
#include <string>
#include <fstream>

class FileHandler
{
public:
	FileHandler(std::string filename);
	~FileHandler();
	std::vector<std::vector<std::string>> parseCsv();
	void writeCsv(std::vector<std::string> dataToWrite);
private:
	std::fstream file;
};

#endif //FILEHANDLER_H