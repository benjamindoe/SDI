#ifndef SDI_CPP
#define SDI_CPP

#include <fstream>
#include <iostream>

#include "SDI.h"

namespace SDI {
	std::vector<std::string> readTextFile(const std::string fileName) {
		std::vector<std::string> textFileContent;
		std::ifstream inFile;
		std::string fileLine;
		inFile.open(fileName);
		if (inFile.is_open()) {
			while (std::getline(inFile, fileLine)) {
				textFileContent.push_back(fileLine);
			}
		}
		else{

		#ifdef _DEBUG
			std::clog << "Could not open" << std::endl;
		#endif

		}
		inFile.close();
		return textFileContent;
	}
}

#endif