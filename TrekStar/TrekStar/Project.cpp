#ifndef PROJECT_CPP
#define PROJECT_CPP

#include <sstream>
#include <iomanip>
#include <map>
#include <cerrno>

#include "Project.h"

using json = nlohmann::json;

Project::Project(json properties)
{
	id = properties["ID"].get<int>();
	projectTitle = properties["Project Title"].is_null() ? "" : properties["Project Title"].get<string>();
	summary = properties["Summary"].is_null() ? "" : properties["Summary"].get<string>();
	genre = properties["Genre"].is_null() ? "" : properties["Genre"].get<string>();
	runtime = properties["Runtime"];
	if (!properties["Release Date"].is_null())
	{
		stringstream ss(properties["Release Date"].get<string>());
			ss >> std::get_time(&releaseDate, "%Y-%m-%d");
			mktime(&releaseDate);
	}

	language = properties["Language"].is_null() ? "" : properties["Language"].get<string>();
	weeklyBoxOffice = properties["Weekly Box Office"].is_null() ? vector<int>() : properties["Weekly Box Office"].get<vector<int>>();
	keywords = properties["Keywords"].is_null() ? vector<string>() : properties["Keywords"].get<vector<string>>();
	status = properties["Status"].get<string>();
	filmingLoc = properties["Filming Locations"].is_null() ? vector<string>() : properties["Filming Locations"].get<vector<string>>();
	for (json material : properties["Materials"])
		projMaterialIds.push_back(material["ID"].get<int>());
}

Project::~Project()
{
}


json Project::getProperties() const
{
	char buffer[50];
	strftime(buffer, 50, "%F", &releaseDate);
	string timeStr(buffer);
	json projProps = { 
		{ "ID", id },
		{ "Project Title", projectTitle }, 
		{ "Summary", summary },
		{ "Genre", genre },
		{ "Release Date", timeStr },
		{ "Language", language },
		{ "Weekly Box Office", weeklyBoxOffice },
		{ "Keywords", keywords },
		{ "Runtime", runtime },
		{ "Status", status }
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

void Project::addBoxOffice(int val)
{
	weeklyBoxOffice.push_back(val);
}
#endif // !PROJECT_CPP

