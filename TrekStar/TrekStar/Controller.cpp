#ifndef CONTROLLER_CPP
#define CONTROLLER_CPP

#include "Controller.h"


Controller::Controller()
{
	model = new Model();
	bool keepOpen = true;
	while (keepOpen)
	{
		int userChoice;
		View::make(View::MAIN);
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


#endif // !CONTROLLER_CPP
