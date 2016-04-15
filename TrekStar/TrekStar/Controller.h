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
	Model* model;
};

#endif // !CONTROLLER_H


