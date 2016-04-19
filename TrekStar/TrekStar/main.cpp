#include <iostream>

#include "Material.h"
#include "Vhs.h"
#include "Disc.h"
#include "ComboBox.h"
#include "DoubleSidedDvd.h"
#include "SimpleFactory.h"
#include "FileHandler.h"
#include "Project.h"

int main(int argc, char* argv[])
{
	
	std::vector<Project *> myProjects;
	FileHandler handlerProj("TrekStar.json");
	//FileHandler handlerMat("materials.csv");

	//std::vector<std::vector<std::string>> projectAttribs = handlerProj.parseCsv();
	//std::vector<std::vector<std::string>> materialAttribs = handlerProj.parseCsv();

	//myProjects.push_back(new Project());
	return 0;
}