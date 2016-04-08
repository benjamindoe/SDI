#include "DoubleSidedDvd.h"


DoubleSidedDvd::DoubleSidedDvd(json properties) : Disc(properties)
{

	sideA = new Disc(properties["Side A"]);
	sideB = new Disc(properties["Side B"]);
}

DoubleSidedDvd::~DoubleSidedDvd()
{
	sideA->~Disc();
	sideB->~Disc();
}

json DoubleSidedDvd::getProperties()
{
	json comboObj;
	comboObj = Material::getProperties();
	comboObj["Side A"] = sideA->getProperties();
	comboObj["Side B"] = sideB->getProperties();
	return comboObj;
}

