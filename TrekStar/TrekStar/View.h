#ifndef VIEW_H
#define VIEW_H

#include <iostream>
#include <sstream>
#include <map>
#include <string>
#include <vector>

#include "JSON\json.hpp"

using namespace std;

typedef nlohmann::json viewData;
class View
{
public:

	typedef map<string, string> viewParams;
	enum Views
	{
		MAIN,
		MAIN_PROJECT,
		MAIN_MATERIAL,
		VIEW_PROJECTS,
		VIEW_MATERIALS,
		VIEW_MATERIAL,
		VIEW_PROJECT
	};
	enum Inputs
	{
		ADD_PROJECT,
		REMOVE_PROJECT,
		ADD_MATERIAL,
		REMOVE_MATERIAL,
		ALTER_PROJECT
	};
	View();
	~View();
	void make(Views view);
	void make(Views view, vector<viewParams> params);
	void make(Views view, viewParams params);
	viewData get(Inputs view);

private:
	void main();                                                           
	void mainProject();
	void mainMaterial();
	void viewMaterials(vector<viewParams> params);
	void viewProjects(vector<viewParams> params);
	ostringstream viewMaterial(viewParams params, bool printStream = false);
	ostringstream viewProject(viewParams params, bool printStream = false);
	viewData addMaterial(bool isCombo = false);
	viewData removeMaterial();
	viewData addProject();
	viewData removeProject();
	viewData alterProject();
};

#endif // !VIEW_H
