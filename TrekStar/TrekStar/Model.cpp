#ifndef MODEL_CPP
#define MODEL_CPP

#include <cerrno>
#include "Model.h"

struct ProjFinder
{
	ProjFinder(const int& id) : id_(id) {}
	bool operator()(const Project* obj) const
	{
		return obj->getId() == id_;
	}
private:
	const int& id_;
};

struct MaterialFinder
{
	MaterialFinder(const int& id) : id_(id) {}
	bool operator()(const Material* obj) const
	{
		return obj->getId() == id_;
	}
private:
	const int& id_;
};

Model::Model(std::string filename)
{
	handler = new FileHandler(filename);
	factory = new SimpleFactory();
	json jData = handler->parseJson();
	materials.reserve(5);
	projects.reserve(5);
	if (!jData.is_null() & jData.is_object())
	{
		root = jData;
	}
	for (json project : root["Projects"])
	{
		try
		{
			this->addProject(project);
		}
		catch (exception& e)
		{
			cerr << e.what();
		}
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
	save();
}

bool Model::addMaterial(int projId, json properties)
{
	auto it = find_if(projects.begin(), projects.end(), ProjFinder(projId));
	if (it != projects.end() || (*it)->getStatus() == "Released")
	{
		vector<int> projMatIds = (*it)->getMaterialIds();
		int materialId = 1;
		if (!projMatIds.empty())
			materialId = (projMatIds.back())++;
		(*it)->addMaterialId(materialId);
		properties["ID"] = materialId;
		materials.push_back(factory->create(properties["Format"], properties));
		return true;
	}
		return false;
}

bool Model::addProject(json properties)
{
	if (properties["ID"].is_null())
	{
		int lastId = projects.back()->getId();
		properties["ID"] = lastId++;
	}
	try
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
		}
		return true;
	}
	catch (const std::exception& e)
	{
		cerr << e.what();
		return false;
	}
}

void Model::removeMaterial(int id, bool removeProjRef)
{
	auto it = find_if(materials.begin(), materials.end(), MaterialFinder(id));
	if (removeProjRef)
	{
		auto projIt = (*find_if(projects.begin(), projects.end(), [it](Project* obj) {return obj->getId() == (*it)->getId();}));
		projIt->removeMaterialId(id);
	}
	materials.erase(std::remove_if(materials.begin(), materials.end(), MaterialFinder(id)));
}

void Model::removeProject(int id)
{
	auto it = find_if(projects.begin(), projects.end(), ProjFinder(id));
	auto deleteMaterials = (*it)->getMaterialIds();
	for (int i : deleteMaterials)
		removeMaterial(i, false);
	projects.erase(std::remove_if(projects.begin(), projects.end(), ProjFinder(id)));
}

void Model::save()
{
	json toParse = getAllProjects();
	handler->writeJson(toParse);
}

json Model::getAllProjects()
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
	json project;
	auto it = find_if(projects.begin(), projects.end(), ProjFinder(id));
	if (it != projects.end())
		project = (*it)->getProperties();

	return project;
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

bool Model::addBoxOffice(int id, int val)
{
	auto it = find_if(projects.begin(), projects.end(), ProjFinder(id));
	if (it != projects.end() && (*it)->getStatus == "Now Playing")
	{
		(*it)->addBoxOffice(val);
		return true;
	}
	return false;
}

#endif // !MODEL_CPP
