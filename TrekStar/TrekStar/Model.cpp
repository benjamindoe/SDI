#include "Model.h"


Model::Model(std::string filename)
{
	handler = new FileHandler(filename);
	json jData = handler->parseJson();
	if (!jData.is_null & jData.is_object)
	{
		root = jData.object;
	}
}


Model::~Model()
{
	delete handler;
	for (Project* it : projects)
		delete it;
	for (Material* it : materials)
		delete it;
}

void Model::addMaterial(json properties)
{
	
}

void Model::addProject(json properties)
{

}

void Model::removeMaterial(int id)
{

}

void Model::removeProject(int id)
{

}