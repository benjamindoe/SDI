#include "Vhs.h"


Vhs::Vhs()
{
}


Vhs::~Vhs()
{
}

void Vhs::setProperties(std::vector<std::string>& properties)
{
	idNumber = std::stoi(properties[1]);
	MaterialTitle = properties[2];
	format = properties[3];
	packagingSpec = properties[4];
	retailPrice = std::stoi(properties[5]);
	language = properties[6];
	subLanguage = properties[7];
	audioFormat = properties[8];
	frameAspect = properties[9];
	runtime = std::stoi(properties[10]);
}

std::vector<std::string> Vhs::getProperties()
{
	std::vector<std::string> tmp;
	tmp.push_back("Disc");
	tmp.push_back(std::to_string(idNumber));
	tmp.push_back(MaterialTitle);
	tmp.push_back(format);
	tmp.push_back(packagingSpec);
	tmp.push_back(std::to_string(retailPrice));
	tmp.push_back(language);
	tmp.push_back(subLanguage);
	tmp.push_back(audioFormat);
	tmp.push_back(frameAspect);
	tmp.push_back(std::to_string(runtime));

	return tmp;
}