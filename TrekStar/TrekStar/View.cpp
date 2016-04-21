#ifndef VIEW_CPP
#define VIEW_CPP

#include <regex>

#include "View.h"

using json = nlohmann::json;

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
		mainMaterial();
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
		viewProjects(params);
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
		viewer(params, true);
		break;
	case View::VIEW_MATERIAL:
		viewer(params, true);
		break;
	default:
		break;
	}
}

viewData View::get(Inputs view)
{
	viewData userInput;
	switch (view)
	{
	case View::ADD_PROJECT:
		userInput = addProject();
		break;
	case View::REMOVE_PROJECT:
		userInput = removeProject();
		break;
	case View::ADD_MATERIAL:
		userInput = addMaterial();
		break;
	case View::ADD_BOX_OFFICE:
		userInput = addBoxOffice();
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
		"2 - Materials\n"
		"0 - Quit\n"
		"Enter number: ";
}

void View::mainProject()
{
	cout << 
		"1 - View Projects\n"
		"2 - Add Project\n"
		"3 - Remove Project\n"
		"4 - Add Weekly Box Office\n"
		"0 - Main Menu\n"
		"Enter number: ";
}

void View::mainMaterial()
{
	cout <<
		"1 - View Materials\n"
		"2 - Add Material\n"
		"3 - Remove Material\n"
		"0 - Main Menu\n"
		"Enter number: ";
}

void View::viewMaterials(vector<viewParams> params)
{
	ostringstream output;
	output
		<< "\nMaterials\n"
		<< "---------\n\n";
	for (viewParams material : params)
	{
		output << viewer(material).str() << "\n";
	}
	output << endl;
	cout << output.str() << endl;
}

void View::viewProjects(vector<viewParams> params)
{
	ostringstream output;
	output
		<< "\nProjects\n"
		<< "---------\n\n";
	for (viewParams proj : params)
	{
		output << viewer(proj).str() << "\n";
	}
	cout << output.str() << endl;
}

ostringstream View::viewer(viewParams params, bool printStream)
{
	ostringstream output;
	for (pair<const string, string> keyVal : params)
	{
		output << keyVal.first << ": " << keyVal.second << "\n";
	}

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
	json matData;
	getIn();
	if (!isCombo)
	{
		cout << "Project ID number: ";
		matData["Project ID"] = stoi(getIn());
	}
	cout << "Title: ";
	matData["Material Title"] = getIn();
	cout << "Format: ";
	matData["Format"] = getIn();
	if (regex_match(matData["Format"].get<string>(), regex("(VHS|DVD|Blu-Ray)")))
	{
		cout << "Runtime: ";
		matData["Runtime"] = stoi(getIn());
		cout << "Frame Aspect: ";
		matData["Frame Aspect"] = getIn();
		cout << "Audio Format: ";
		matData["Audio Format"] = getIn();	
		if (matData["Format"] == "DVD" || matData["Format"] == "Blu-Ray")
		{
			bool anotherLang = true;
			cout << "Languages\n";
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
						anotherLang = regex_match(userSel, regex("(Yes|yes|[Yy])"));
					}
				}
			}

			cout << "Subtitle Languages\n";
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
						anotherLang = regex_match(userSel, regex("(Yes|yes|[Yy])"));
					}
				}
			}
		}
		else if (matData["Format"] == "VHS")
		{
			cout << "Language: ";
			matData["Language"] = getIn();
			cout << "Subtitle Language: ";
			matData["Subtitle Language"] = getIn();
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

	cout << "Retail Price: ";
	matData["Retail Price"] = stod(getIn());
	cout << endl;
	return matData;

}

viewData View::addProject()
{
	cout << endl;
	viewData projData;
	cout << "Title: ";
	projData["Title"] = getIn();
	cout << "Summary: ";
	projData["Summary"] = getIn();
	cout << "Genre: ";
	projData["Genre"] = getIn();
	cout << "Release Date: ";
	projData["Release Date"] = getIn();
	cout << "Language: ";
	projData["Language"] = getIn();
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
				moreKw = regex_match(userSel, regex("(Yes|yes|[Yy])"));
				cout << endl;
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
		getIn();
		key = getIn();
		cout << "Name: ";	
		val = getIn();
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
				moreCast = regex_match(userSel, regex("(Yes|yes|[Yy])"));
				cout << endl;
			}
		}
	}
	cout << "Status: ";
	projData["Status"] = getIn();
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
						moreMaterial = regex_match(userSel, regex("(Yes|yes|[Yy])"));
					}
				}
			}
		}
	}

	return projData;
}

viewData View::removeProject()
{
	
	viewData output;
	cout << "Enter valid project ID number: ";
	output["ID"] = stoi(getIn());
	return output;
}

viewData View::removeMaterial()
{
	
	viewData output;
	cout << "Enter valid material ID number: ";
	output["ID"] = stoi(getIn());
	return output;
}

viewData View::addBoxOffice()
{
	getIn();
	viewData j;
	cout << "Project ID: ";
	j["ID"] = stoi(getIn());
	cout << "Weekly Box Office";
	j["Value"] = stoi(getIn());
	return j;
}

string View::getIn() const
{
	string usrStr;
	getline(cin, usrStr, '\n');
	return usrStr;
}

#endif // !VIEW_CPP