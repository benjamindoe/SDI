#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <ctime>
#include <map>

class Project
{
public:
	Project(std::vector<std::string> parsed);
	~Project();
	std::vector<std::string> Project::getProject();
private:
	std::string projectTitle;
	std::string summary;
	std::string genre;
	std::time_t releaseDate;
	std::string language;
	int weeklyBoxOffice;
	std::vector<std::string> keywords;
};

#endif //PROJECT_H