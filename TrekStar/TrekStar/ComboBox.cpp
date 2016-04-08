#include "ComboBox.h"

ComboBox::ComboBox(json properties) : Material(properties)
{
	for (int i = 0; i < properties["Discs"].size(); i++)
	{
		Disc* tmpDisc = new Disc(properties["Discs"].at(i));
		ComboDiscs.push_back(tmpDisc);
	}
}

ComboBox::~ComboBox()
{
	ComboDiscs.~vector();
}

json ComboBox::getProperties()
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
