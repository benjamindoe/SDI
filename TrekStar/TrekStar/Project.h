#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <ctime>
#include <map>

using json = nlohmann::json;
using namespace std;

class Project
{
public:
	Project(json properties);
	~Project();
	std::vector<std::string> Project::getProject();
private:
	string projectTitle;
	string summary;
	string genre;
	time_t releaseDate;
	string language;
	int weeklyBoxOffice;
	vector<string> keywords;
	vector<int*> projMaterials;
};

#endif //PROJECT_H