#ifndef PROJECT_H
#define PROJECT_H

#include <string>
#include <vector>
#include <ctime>
#include <map>

#include "Material.h"
#include "Vhs.h"
#include "DoubleSidedDvd.h"
#include "ComboBox.h"
#include "FileHandler.h"

class Project
{
public:
	Project(std::string filename);
	~Project();
	void addMaterial(std::vector<std::string> matProp);
	void saveProject();
private:
	std::string projectTitle;
	std::string summary;
	std::string genre;
	std::time_t releaseDate;
	std::string language;
	int weeklyBoxOffice;
	std::vector<Material*> projectMaterials;
	std::vector<std::string> keywords;
	FileHandler* handler;
	std::map<std::string, Material*> materialMap;
};

#endif //PROJECT_H