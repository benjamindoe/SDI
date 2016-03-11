#include <sstream>
#include <iomanip>
#include <map>

#include "Project.h"


Project::Project(std::string filename)
{
	materialMap["VHS"] = new Vhs();
	materialMap["Disc"] = new Disc();
	materialMap["Double Sided DVD"] = new DoubleSidedDvd();
	materialMap["ComboBox"] = new ComboBox();

	
	std::vector<std::vector<std::string>> parsed = handler->parseCsv();
	projectTitle = parsed[0][0];
	summary = parsed[0][1];
	genre = parsed[0][2];

	struct tm tm;
	std::stringstream tmpSs(parsed[0][3]);
	tmpSs >> std::get_time(&tm, "%F");
	releaseDate = mktime(&tm);

	language = parsed[0][4];
	weeklyBoxOffice = std::stoi(parsed[0][5]);

	for (std::vector<std::string>::iterator it = parsed[0].begin() + 5; it != parsed[0].end(); it++)
		keywords.push_back(*it);

	for (std::size_t i = 1; i != parsed.size(); i++)
	{
		std::vector<std::string> tmpVec = parsed[i];
		projectMaterials.push_back(materialMap[tmpVec[0]]);
		projectMaterials[i]->setProperties(tmpVec); 
	}
	handler->~FileHandler();
}
        

Project::~Project()
{
	handler->~FileHandler();
}

void Project::addMaterial(std::vector<std::string> matProp)
{
	projectMaterials.push_back(materialMap[matProp[0]]);
	projectMaterials.back()->setProperties(matProp);
}

void Project::saveProject() 
{
	handler = new FileHandler(projectTitle + ".csv");
	std::vector<std::string> writeVec;
	std::ostringstream ss;
	char buffer[20];
	struct tm tm;
	localtime_s(&tm, &releaseDate);
	ss << projectTitle << ',' << summary << ',' << genre << ',' << strftime(buffer, 20, "%F", &tm) << ',' << language << ',' << weeklyBoxOffice << "\n";
	writeVec.push_back(ss.str());
	for (unsigned int i = 0; i < projectMaterials.size(); i++)
	{
		ss.clear();
		ss.str(std::string());
		std::vector<std::string> tmp = projectMaterials[i]->getProperties();
		for (std::vector<std::string>::iterator it = tmp.begin(); it != tmp.end(); it++)
		{
			if (it != tmp.begin()) ss << ',';
			ss << *it;
		}
		ss << "\n";
		writeVec.push_back(ss.str());
	}
	handler->writeCsv(writeVec);

}