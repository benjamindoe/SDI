#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

#include "Controller.h"


Controller::Controller()
{
	model = new Model();
	view = new View();
	bool keepOpen = true;
	while (keepOpen)
	{
		int userChoice;
		view->make(View::MAIN);
		cin >> userChoice;
		switch (userChoice)
		{
		case 1:
			break;
		case 2:
			break;
		case 0:
			keepOpen = false;
		default:
			break;
		}
	}

}


Controller::~Controller()
{
}

void Controller::materials()
{
	bool menuSelect = false;
	while (!menuSelect)
	{
		int userChoice;
		view->make(View::MAIN_MATERIAL);
		cin >> userChoice;
		menuSelect = true;
		switch (userChoice)
		{
		case 1:
			view->make(View::VIEW_MATERIALS);
			break;
		case 2:
			break;
		case 3:
			break;
		case 0:
			break;
		default:
			menuSelect = false;
			break;
		}
	}
}

void Controller::viewMaterials()
{
	json j = model->getAllMaterials();
	vector<map<string, string>> viewProperties;
	for (auto ele : j)
	{
		map<string, string> viewMaterial = {
				{ "Title", ele["Title"].get<string>() },
				{ "ID", ele["ID"].get<string>() },
				{ "Format", ele["Format"].get<string>() },
				{ "Retail Price", ele["Retail Price"] }
		};
	}
}

void Controller::removeMaterial()
{

}

void Controller::removeProject()
{

}

void Controller::addProject()
{

}

void Controller::addMaterial()
{

}
#endif // !CONTROLLER_CPP
