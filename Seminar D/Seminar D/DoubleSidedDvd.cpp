#include "DoubleSidedDvd.h"


DoubleSidedDvd::DoubleSidedDvd()
{
}

DoubleSidedDvd::DoubleSidedDvd(std::vector<std::string>&properties)
{
	setProperties(properties);
}

DoubleSidedDvd::~DoubleSidedDvd()
{
}

void DoubleSidedDvd::setProperties(std::vector<std::string>& properties)
{


	int sideASize = calcDiscVecSize(properties, 7);
	std::vector<std::string> sideAVec(properties.begin() + 1, properties.begin() + sideASize);
	std::vector<std::string> sideBVec(properties.begin() + sideASize, properties.end());
	
	sideA = new Disc(sideAVec);
	sideB = new Disc(sideBVec);
}

std::vector<std::string> DoubleSidedDvd::getProperties()
{
	std::vector<std::string> aVec;
	std::vector<std::string> bVec;
	aVec = sideA->getProperties();
	bVec = sideB->getProperties();
	aVec.insert(aVec.end(), bVec.begin(), bVec.end());
	return aVec;
}

