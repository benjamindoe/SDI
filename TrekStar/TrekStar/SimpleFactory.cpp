#include "SimpleFactory.h"
#include <iostream>

SimpleFactory::SimpleFactory()
{
}


SimpleFactory::~SimpleFactory()
{
}

Material* SimpleFactory::create(std::string materialType, json data)
{
	Material* materialPtr;
	if (materialType == "VHS")
	{
		materialPtr = new Vhs(data);
	}
	else if (materialType == "BluRay" || materialType == "DVD")
	{
		materialPtr = new Disc(data);
	}
	else if (materialType == "ComboBox")
	{
		materialPtr = new ComboBox(data);
	}
	else if (materialType == "Double Sided DVD")
	{
		materialPtr = new DoubleSidedDvd(data);
	}
	else
	{
		std::cerr << "Invalid material type." << std::endl;
	}
	return materialPtr;
}
