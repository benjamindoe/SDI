#include <iostream>

#include "Project.h"

int main(int argc, char* argv[])
{
	
	std::vector<Project *> myProjects;
	FileHandler * handler = new FileHandler("materials.csv");

	handler->parseCsv();

	myProjects.push_back(Project();)
	return 0;
}