#ifndef SIMPLEFACTORY_H
#define SIMPLEFACTORY_H

#include <map>
#include <string>

#include "Material.h"
#include "Vhs.h"
#include "DoubleSidedDvd.h"
#include "ComboBox.h"

class SimpleFactory
{
public:
	SimpleFactory();
	~SimpleFactory();
	Material* create(std::string materialType, json data);
};

#endif