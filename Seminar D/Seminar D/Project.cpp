#include <sstream>
#include <iomanip>
#include <map>

#include "Project.h"


Project::Project(std::vector<std::string> parsed)
{
	
	projectTitle = parsed[0];
	summary = parsed[1];
	genre = parsed[2];

	struct tm tm;
	std::stringstream tmpSs(parsed[3]);
	tmpSs >> std::get_time(&tm, "%F");
	releaseDate = mktime(&tm);

	language = parsed[4];
	weeklyBoxOffice = std::stoi(parsed[5]);

	for (std::vector<std::string>::iterator it = parsed.begin() + 5; it != parsed.end(); it++)
		keywords.push_back(*it);
}
        

Project::~Project()
{
}


std::vector<std::string> Project::getProject() 
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