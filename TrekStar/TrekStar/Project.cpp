#ifndef PROJECT_CPP
#define PROJECT_CPP

#include <sstream>
#include <iomanip>
#include <map>

#include "Project.h"


Project::Project(json properties)
{
	
	projectTitle = properties["Project Title"].get<string>();
	summary = properties["Summary"].get<string>();
	genre = properties["Genre"].get<string>();

	struct tm tm;
	std::stringstream tmpSs(properties["Release Date"].get<string>());
	tmpSs >> std::get_time(&tm, "%F");
	releaseDate = mktime(&tm);

	language = properties["Lanuguage"].get<string>();
	weeklyBoxOffice = properties["Weekly Box Office"].get<int>();
	keywords = properties["Keywords"].get<vector<string>>();

	for (json material : properties["Materials"])
		projMaterialIds.push_back(material["ID"].get<int>());
}

Project::~Project()
{
}


json Project::getProperties() const
{
	char buffer[20];
	struct tm tm;
	localtime_s(&tm, &releaseDate);
	std::stringstream ssTime;
	ssTime << strftime(buffer, 20, "%F", &tm);
	std::vector<std::string> rVec = { projectTitle, summary, genre, ssTime.str(), language, std::to_string(weeklyBoxOffice) };
   /*
	* For < C++11,
	* int arr[] = { projectTitle, summary, genre, ssTime.str(), language, std::to_string(weeklyBoxOffice) }
	* std::vector<std::string> rVec(arr, arr + 6);
	*
	*/

	return rVec;
}

string Project::getTitle() const
{
	return projectTitle;
}

int Project::getId() const
{
	return id;
}

string Project::getStatus() const
{
	return status;
}

void Project::addMaterialId(int materialId)
{
	projMaterialIds.push_back(materialId);
}

vector<int> Project::getMaterialIds() const
{
	return projMaterialIds;
}


#endif // !PROJECT_CPP

