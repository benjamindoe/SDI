#ifndef DOUBLE_SIDED_DVD_CPP
#define DOUBLE_SIDED_DVD_CPP

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
	json tmp = Material::getProperties();
	tmp["Side A"] = sideA->getProperties();
	tmp["Side B"] = sideB->getProperties();
	return tmp;
}

#endif // !DOUBLE_SIDED_DVD_CPP