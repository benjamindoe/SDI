#ifndef MODEL_CPP
#define MODEL_CPP


#include "Model.h"


Model::Model(std::string filename)
{
	handler = new FileHandler(filename);
	factory = new SimpleFactory();
	json jData = handler->parseJson();
	if (!jData.is_null() & jData.is_object())
	{
		root = jData.object();
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
	vector<Project*>::iterator it = find(projects.begin(), projects.end(), [&projId](Project* obj) {return obj->getId() == projId;});
	if (it != projects.end() || (*it)->getStatus() == "Released")
	{
		int materialId = (*it)->getMaterialIds().back + 1;
		(*it)->addMaterialId(materialId);
		properties["ID"] = materialId;
		materials.push_back(factory->create(properties["Material Type"], properties));
		return true;
	}
		return false;
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
			projects.back()->addMaterialId(mat["ID"]);
			materials.push_back(factory->create(mat["Material Type"], mat));
		}
	return true;
	}
	return false;
}

void Model::removeMaterial(int id)
{
	auto it = find(materials.begin(), materials.end(), id);
	materials.erase(std::remove(materials.begin(), materials.end(), id), materials.end());
	(*find(projects.begin(), projects.end(), (*it)->getProjId()))->removeMaterialId(id);
}

void Model::removeProject(int id)
{
	auto it = find(projects.begin(), projects.end(), id);
	auto deleteMaterials = (*it)->getMaterialIds();
	projects.erase(std::remove(projects.begin(), projects.end(), id), projects.end());
	for (int i : deleteMaterials)
		materials.erase(std::remove(materials.begin(), materials.end(), i), materials.end());
}

void Model::save()
{
	json toParse = getAllProjects();
	handler->writeJson(toParse);
}

json Model::getAllMaterials()
{
	json parsed;
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
		parsed["Projects"].push_back(projJson);
	}
	return parsed;
}

json Model::getProjectById(int id)
{
	auto it = find(projects.begin(), projects.end(), [&id](Project* obj) {return obj->getId() == id; });
}

json Model::getAllMaterials()
{
	json materialJson;
	for (Material* material : materials)
	{
		materialJson["Materials"].push_back(material->getProperties());
	}
	return materialJson;
}
#endif // !MODEL_CPP
