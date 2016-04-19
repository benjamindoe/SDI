#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <ctime>
#include <map>
#include "JSON\json.hpp"
using json = nlohmann::json;

using namespace std;

class Project
{
public:
	Project(json properties);
	~Project();

	void addMaterialId (int materialId);

	/*
	 * Getters
	 */
	json Project::getProperties() const;
	string getTitle() const;
	int getId() const;
	string getStatus() const;
	vector<int> getMaterialIds() const;
private:
	int id;
	string projectTitle;
	string summary;
	string genre;
	time_t releaseDate;
	string language;
	int weeklyBoxOffice;
	vector<string> keywords;
	vector<int> projMaterialIds;
	vector<pair<string, string>> castAndCrew;
	string status;
};

#endif // !PROJECT_H