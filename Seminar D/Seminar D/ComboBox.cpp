#include "ComboBox.h"


ComboBox::ComboBox()
{
}


ComboBox::~ComboBox()
{
}

void ComboBox::setProperties(std::vector<std::string>& properties)
{
	idNumber = std::stoi(properties[1]);
	MaterialTitle = properties[2];
	format = properties[3];
	packagingSpec = properties[4];
	retailPrice = std::stoi(properties[5]);
}


std::vector<std::string> ComboBox::getProperties()
{
	std::vector<std::string> tmp;
	tmp.push_back("ComboBox");
	tmp.push_back(std::to_string(idNumber));
	tmp.push_back(MaterialTitle);
	tmp.push_back(format);
	tmp.push_back(packagingSpec);
	tmp.push_back(std::to_string(retailPrice));
	for (std::vector<Disc*>::iterator it = ComboDiscs.begin(); it != ComboDiscs.end(); it++)
	{
		std::vector<std::string> DiscProperties = (*it)->getProperties();
		tmp.insert(tmp.end(), DiscProperties.begin(), DiscProperties.end());
	}
	return tmp;
}