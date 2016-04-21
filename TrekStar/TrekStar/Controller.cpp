#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

#include <cerrno>
#include <regex>
#include "Controller.h"


Controller::Controller()
{
	/*
	 * 1 - Projects
	 * 2 - Materials
	 * 0 - Quit
	 */
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
			projects();
			break;
		case 2:
			materials();
			break;
		case 0:
			keepOpen = false;
			model->save();
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
	/*
	 * 1 - View
	 * 2 - Add
	 * 3 - Remove
	 * 0 - Main menu
	 */
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
			viewMaterials();
			break;
		case 2:
			addMaterial();
			break;
		case 3:
			removeMaterial();
			break;
		case 0:
			break;
		default:
			menuSelect = false;
			break;
		}
	}
}

void Controller::projects()
{
	/*
	* 1 - View
	* 2 - Add
	* 3 - Remove
	* 0 - Main menu
	*/
	bool menuSelect = false;
	while (!menuSelect)
	{
		int userChoice;
		view->make(View::MAIN_PROJECT);
		cin >> userChoice;
		menuSelect = true;
		switch (userChoice)
		{
		case 1:
			viewProjects();
			break;
		case 2:
			addProject();
			break;
		case 3:
			removeProject();
			break;
		case 4:
			addBoxOffice();
			break;
		case 0:
			break;
		default:
			menuSelect = false;
			break;
		}
	}
}

void Controller::viewProjects()
{
	json j = model->getAllProjects();
	vector<map<const string, string>> viewProperties;
	for (auto ele : j["Projects"])
	{
		try
		{
			map<const string, string> projProps = {
				{ "Title", ele["Project Title"].get<string>() },
				{ "ID", to_string(ele["ID"].get<int>()) },
				{ "Genre", ele["Genre"].get<string>() },
				{ "Release Date", ele["Release Date"].get<string>() },
				{ "Status", ele["Status"].get<string>() }
			};
			viewProperties.push_back(projProps);

		}
		catch (const std::exception& e)
		{
			cerr << e.what();
		}
	}
	view->make(View::VIEW_PROJECTS, viewProperties);
}

void Controller::viewMaterials()
{
	json j = model->getAllMaterials();
	vector<map<const string, string>> viewProperties;
	for (auto ele : j["Materials"])
	{
		map<const string, string> materialProps = {
				{ "Title", ele["Material Title"].get<string>() },
				{ "ID", ele["ID"].get<string>() },
				{ "Format", ele["Format"].get<string>() },
				{ "Retail Price", ele["Retail Price"].get<string>() },
				{ "Packaging Specification", ele["Packaging Specification"].get<string>() }
		};
		string sep = "";
		stringstream langStr;
		for (auto lang : ele["Language"])
		{
			langStr << sep << lang.get<string>();
			sep = ",";
		}
		viewProperties.push_back(materialProps);
	}
	view->make(View::VIEW_MATERIALS, viewProperties);
}

void Controller::removeMaterial()
{
	int id = view->get(View::REMOVE_MATERIAL)["ID"].get<int>();
	model->removeMaterial(id);
}

void Controller::removeProject()
{
	int id = view->get(View::REMOVE_PROJECT)["ID"].get<int>();
	model->removeProject(id);

}

void Controller::addProject()
{
	json j = view->get(View::ADD_PROJECT);
	model->addProject(j);
}

void Controller::addMaterial()
{
	json j = view->get(View::ADD_MATERIAL);
	if (regex_match(j["Format"].get<string>(), regex("DVD|Blu-Ray|VHS")))
	{
		j["Packaging Specification"] = "Plastic Box";
	}
	else
	{
		j["Packaging Specification"] = "Cardboard Box";
	}
	model->addMaterial(j["Project ID"], j);
}

void Controller::addBoxOffice()
{
	json j = view->get(View::ADD_BOX_OFFICE);
	model->addBoxOffice(j["ID"].get<int>(), j["Value"].get<int>());
}
#endif // !CONTROLLER_CPP
