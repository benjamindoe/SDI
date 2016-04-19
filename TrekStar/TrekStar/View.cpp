#ifndef VIEW_CPP
#define VIEW_CPP

#include <regex>

#include "View.h"


View::View()
{
}


View::~View()
{
}

void View::make(Views view)
{
	switch (view)
	{
	case Views::MAIN:
		main();
		break;
	case Views::MAIN_PROJECT:
		mainProject();
		break;
	case Views::MAIN_MATERIAL:
		addMaterial();
		break;
	default:
		break;
	}
}

void View::make(Views view, vector<viewParams> params)
{
	switch (view)
	{
	case View::VIEW_PROJECTS:
		//viewProjects(params);
		break;
	case View::VIEW_MATERIALS:
		viewMaterials(params);
		break;
	default:
		break;
	}
}

void View::make(Views view, viewParams params)
{
	switch (view)
	{
	case View::VIEW_PROJECT:
		//viewProject(params, true);
		break;
	case View::VIEW_MATERIAL:
		viewMaterial(params, true);
		break;
	default:
		break;
	}
}

map<string, string> View::get(Inputs view)
{
	map<string, string> userInput;
	switch (view)
	{
	case View::ADD_PROJECT:
		userInput = addProject();
		break;
	case View::REMOVE_PROJECT:
		//userInput = removeProject();
		break;
	case View::ADD_MATERIAL:
		userInput = addMaterial();
		break;
	case View::REMOVE_MATERIAL:
		//userInput = removeMaterial();
		break;
	case View::ALTER_PROJECT:
		//userInput = alterProject();
		break;
	default:
		break;
	}
	return userInput;
}

void View::main()
{
	cout << 
		"1 - Projects\n"
		"2 - Materials"
		<< endl;
}

void View::mainProject()
{
	cout << 
		"1 - View Projects\n"
		"2 - Add Project\n"
		"3 - Remove Project"
		<< endl;
}

void View::mainMaterial()
{
	cout <<
		"1 - View Materials\n"
		"2 - Add Material\n"
		"3 - Remove Material"
		<< endl;
}

void View::viewMaterials(vector<viewParams> params)
{
	ostringstream output;
	for (viewParams material : params)
	{
	}
}

ostringstream View::viewMaterial(viewParams params, bool printStream)
{
	ostringstream output;
	output
		<< ""
		<< "Title: " << params["title"] << "\n"
		<< "ID Number" << params["id"] << "\n"
		<< "Format: " << params["format"] << "\n"
		<< "Runtime: " << params["runtime"] << "\n"
		<< "Language(s): ";
	
	stringstream ss(params["language"]);
	string token;
	while (getline(ss, token, ','))
		output << token << '\n';

	output
		<< endl;

	if (printStream)
	{
		cout << output.str();
		output.str("");
		output.clear();
	}
	return output;
}

viewData View::addMaterial()
{
	viewData matData;
	cout << "Project ID number: ";
	cin >> matData["projId"];
	cout << "Title: ";
	cin >> matData["title"];
	cout << "Format: ";
	cin >> matData["format"];
	cout << "Runtime: ";
	cin >> matData["runtime"];
	if (matData["format"] == "DVD" || matData["format"] == "Blu-Ray")
	{
		stringstream langStream;
		bool anotherLang = true;
		string seperate = "";
		cout << "Languages:\n";
		while (anotherLang)
		{
			string str;
			cout << "Languange: ";
			cin >> str;
			langStream << seperate << str;
			seperate = ",";

			bool again = true;
			while (again)
			{
				string userSel;
				cout << "Add another lanuage? (Y/N)";
				cin >> userSel;
				regex expression("(Yes|No|yes|no|[YyNn])");
				if (regex_match(userSel, expression))
					again = false;
			}
		}
		matData["Languages"] = langStream.str();
	}
	else
	{
		cout << "Langauge: ";
		cin >> matData["Language: "];
	}
	cout << endl;
	return matData;

}

viewData View::addProject()
{
	viewData projData;
	cout << "Title: ";
	cin >> projData["title"];
	cout << "Summary: ";
	cin >> projData["summary"];
	cout << "Genre: ";
	cin >> projData["genre"];
	cout << "Release Date: ";
	cin >> projData["releaseDate"];
	cout << "Language: ";
	cin >> projData["language"];



	return projData;
}
#endif // !VIEW_CPP