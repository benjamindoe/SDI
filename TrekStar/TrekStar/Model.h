#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <map>

#include "JSON\JSON.hpp"
using json = nlohmann::json;

#include "FileHandler.h"
#include "Project.h"
#include "SimpleFactory.h"

#include "Material.h"
#include "ComboBox.h"
#include "Disc.h"
#include "DoubleSidedDvd.h"
#include "Vhs.h"

class Model
{
public:
	Model(std::string filename);
	~Model();
	void addMaterial(json properties);
	void addProject(json properties);
	void removeMaterial(int id);
	void removeProject(int id);
private:
	std::vector<Project*> projects;
	std::vector<Material*> materials;
	json root;
	FileHandler* handler;
};

#endif // !MODEL_H


