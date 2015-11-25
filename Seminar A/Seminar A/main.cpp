#include <iostream>
#include <string>
#include "SDI.h"
int main() {

	std::vector<std::string> outputVector = SDI::readTextFile("text.txt");
	return 0;
}