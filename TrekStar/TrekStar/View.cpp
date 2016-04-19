#ifndef VIEW_CPP
#define VIEW_CPP

#include <regex>

#include "View.h"

using namespace std;

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

viewData View::get(Inputs view)
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
		<< "Format: " << params["Format"] << "\n"
		<< "Runtime: " << params["runtime"] << "\n"
		<< "Language(s): ";
	
	stringstream ss(params["Language"]);
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

viewData View::addMaterial(bool isCombo)
{
	nlohmann::json matData;
	if (!isCombo)
	{
		cout << "Project ID number: ";
		cin >> matData["projId"];
	}
	cout << "Title: ";
	cin >> matData["Title"];
	cout << "Format: ";
	cin >> matData["Format"];
	if (regex_match(matData["Format"].get<std::string>(), regex("(VHS|DVD|Blu-Ray)")))
	{
		cout << "Runtime: ";
		cin >> matData["Runtime"];
		cout << "Aspect Ratio";
		cin >> matData["Aspect Ratio"];
		cout << "Audio Format";
		cin >> matData["Audio Format"];	
		if (matData["Format"] == "DVD" || matData["Format"] == "Blu-Ray")
		{
			bool anotherLang = true;
			cout << "Languages:\n";
			while (anotherLang)
			{
				string str;
				cout << "Language: ";
				cin >> str;
				matData["Languages"].push_back(str);

				bool again = true;
				while (again)
				{
					string userSel;
					cout << "Add another lanuage? (Y/N)";
					cin >> userSel;
					regex expression("(Yes|No|yes|no|[YyNn])");
					if (regex_match(userSel, expression))
					{
						again = false;
						anotherLang = regex_match(userSel, regex("(Yes|yes|[Yy]"));
					}
				}
			}

			cout << "Subtitle Languages: ";
			anotherLang = true;
			while (anotherLang)
			{
				string str;
				cout << "Language: ";
				cin >> str;
				matData["Subtitle Language"].push_back(str);

				bool again = true;
				while (again)
				{
					string userSel;
					cout << "Add another subtitle lanuage? (Y/N)";
					cin >> userSel;
					regex expression("(Yes|No|yes|no|[YyNn])");
					if (regex_match(userSel, expression))
					{
						again = false;
						anotherLang = regex_match(userSel, regex("(Yes|yes|[Yy]"));
					}
				}
			}
		}
		else if (matData["Format"] == "VHS")
		{
			cout << "Language: ";
			cin >> matData["Language: "];
			cout << "Subtitle Language";
			cin >> matData["Subtitle Language"];
		}
	}
	else if (regex_match(matData["Format"].get<string>(), regex("(ComboBox|Double Sided DVD)"))){
		if (matData["Format"] = "ComboBox")
		{
			int noDVD;
			cout << "Number of DVDs";
			cin >> noDVD;
			for (int i = 0; i < noDVD; i++)
				matData["Discs"].push_back(addMaterial(true));
		}
		else 
		{
			cout << "Side A";
			matData["Side A"] = addMaterial(true);
			
			cout << "Side B";
			matData["Side B"] = addMaterial(true);
		}
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
	cin >> projData["Language"];
	cout << "Keywords\n";
	bool moreKw = true;
	while (moreKw)
	{
		string keyword;
		cout << "Keyword: ";
		cin >> keyword;
		projData["Keywords"].push_back(keyword);
		bool again = true;
		while (again)
		{
			string userSel;
			cout << "Add another keyword? (Y/N)";
			cin >> userSel;
			regex expression("(Yes|No|yes|no|[YyNn])");
			if (regex_match(userSel, expression))
			{
				again = false;
				moreKw = regex_match(userSel, regex("(Yes|yes|[Yy]"));
			}
		}
	}
	bool moreCast = true;
	while (moreCast)
	{
		string key;
		string val;
		viewData cast;
		cout << "Role: ";
		cin >> key;
		cout << "Name: ";
		cin >> val;
		cast = { { key, val } };
		projData["Cast and Crew"].push_back(cast);
		bool again = true;
		while (again)
		{
			string userSel;
			cout << "Add another cast/crew member? (Y/N)";
			cin >> userSel;
			regex expression("(Yes|No|yes|no|[YyNn])");
			if (regex_match(userSel, expression))
			{
				again = false;
				moreCast = regex_match(userSel, regex("(Yes|yes|[Yy]"));
			}
		}
	}
	cout << "Status: ";
	cin >> projData["Status"];
	if (projData["Status"].get<string>() == "Released")
	{
		cout << "Add Materials now? (Y/N): ";
		string userSel;
		cin >> userSel;
		if (regex_match(userSel, regex("(Yes|yes|[Yy])")))
		{
			bool moreMaterial = true;
			while (moreMaterial)
			{
				projData["Materials"].push_back(addMaterial());
				bool again = true;
				while (again)
				{
					string userSel;
					cout << "Add another cast/crew member? (Y/N)";
					cin >> userSel;
					regex expression("(Yes|No|yes|no|[YyNn])");
					if (regex_match(userSel, expression))
					{
						again = false;
						moreMaterial = regex_match(userSel, regex("(Yes|yes|[Yy]"));
					}
				}
			}
		}
	}

	return projData;
}
#endif // !VIEW_CPP