#pragma once
class View
{
public:

	enum Menus
	{
		MAIN,
		VIEW_MATERIALS,
		ADD_MATERIALS,
		REMOVE_MATERIALS,
		VIEW_PROJECTS,
		ADD_PROJECT,
		REMOVE_PROJECT,
		ALTER_PROJECT
	};

	View();
	~View();
	void make(View::Menus menuType);

private:

};

