#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <string>

#include "JSON\json.hpp"
using json = nlohmann::json;

#include "Model.h"
#include "View.h"

using namespace std;

class Controller
{
public:
	Controller();
	~Controller();

private:
	void projects();
	void viewProjects();
	void addProject();
	void removeProject();
	void addBoxOffice();

	void materials();
	void viewMaterials();
	void addMaterial();
	void removeMaterial();


	Model* model;
	View* view;
};

#endif // !CONTROLLER_H


