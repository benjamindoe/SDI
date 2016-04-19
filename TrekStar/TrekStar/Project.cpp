#ifndef PROJECT_CPP
#define PROJECT_CPP

#include <sstream>
#include <iomanip>
#include <map>

#include "Project.h"

using json = nlohmann::json;

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
	json projProps;
	char buffer[20];
	struct tm tm;
	localtime_s(&tm, &releaseDate);
	std::stringstream ssTime;
	ssTime << strftime(buffer, 20, "%F", &tm);
	json projProps = { 
			{ "Project Title", projectTitle }, 
			{ "Summary", summary },
			{ "Genre", genre },
			{ "Release Date", ssTime.str() },
			{ "Language", language },
			{ "Weekly Box Office", to_string(weeklyBoxOffice) }
	};

	return projProps;
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

void Project::removeMaterialId(int id)
{
	projMaterialIds.erase(std::remove(projMaterialIds.begin(), projMaterialIds.end(), id), projMaterialIds.end());
}
#endif // !PROJECT_CPP

