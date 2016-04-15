#ifndef MODEL_CPP
#define MODEL_CPP


#include "Model.h"


Model::Model(std::string filename)
{
	handler = new FileHandler(filename);
	factory = new SimpleFactory();
	json jData = handler->parseJson();
	if (!jData.is_null & jData.is_object)
	{
		root = jData.object;
	}
	for (json project : root["Projects"])
	{
		this->addProject(project);
	}
}


Model::~Model()
{
	delete handler;
	delete factory;
	for (Project* it : projects)
		delete it;
	for (Material* it : materials)
		delete it;
}

bool Model::addMaterial(int projId, json properties)
{
	vector<Project*>::iterator it = find_if(projects.begin(), projects.end(), [&projId](const Project& obj) {return obj.getId() == projId;});
	if (it != projects.end() || (*it)->getStatus() == "Unreleased" && (*it)->getStatus() == "Now Playing")
		return false;

	materials.push_back(factory->create(properties["Material Type"], properties));
	return true;


}

bool Model::addProject(json properties)
{
	Project* tmp = new Project(properties);
	projects.push_back(tmp);
	if (!properties["Materials"].is_null())
	{
		for (json mat : properties["Materials"])
		{
			this->addMaterial(properties["ID"].get<int>(), mat);
			projects.back()->addMaterialRef(mat["ID"]);
		}
	}
}

void Model::removeMaterial(int id)
{

}

void Model::removeProject(int id)
{

}

void Model::save()
{
	json toParse;
	for (Project* proj : projects)
	{
		json projJson = proj->getProperties();
		for (Material* mat : materials)
		{
			vector<int> projMatIds = proj->getMaterialIds();
			auto it = find(projMatIds.begin(), projMatIds.end(), mat->getId());
			if (it != projMatIds.end())
			{
				json matJson = mat->getProperties();
				projJson["Materials"].push_back(matJson);
			}
		}
		toParse["Projects"].push_back(projJson);
	}
	handler->writeJson(toParse);
}


#endif // !MODEL_CPP
