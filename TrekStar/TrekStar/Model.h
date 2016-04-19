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

using namespace std;

class Model
{
public:
	/*
	 * Construct and destruct
	 */
	Model(string filename = "TrekStar.json");
	~Model();
	
	/*
	 * Manipulating the material and projects.
	 */
	bool addMaterial(int projectId, json properties);
	bool addProject(json properties);
	void removeMaterial(int id);
	void removeProject(int id);

	/*
	 * Search members and getters
	 */
	json getAllProjects();
	json getAllMaterials();
	json getProjectById(int id);
	json getMaterialById(int id);
	json getProjectsByTitle(string projectTitle);
	json searchByMaterialsByTitle(string materialTitle);
	//json getProjectsByKeywords(string keyword);
	// map<string, string> searchProjectByActor(string projetName);

	void save();
private:
	vector<Project*> projects;
	vector<Material*> materials;
	json root;
	FileHandler* handler;
	SimpleFactory* factory;
};

#endif // !MODEL_H


