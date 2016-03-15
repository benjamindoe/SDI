#include "ComboBox.h"


ComboBox::ComboBox(std::vector<std::string>& properties) : Material(properties)
{
	int noOfDiscs = std::stoi(properties[6]);
	int offset = 6;
	for (int i = 0; i < noOfDiscs; i++)
	{
		int vecSize = calcDiscVecSize(properties, offset);
		std::vector<std::string> tmpVector(properties.begin() + offset, properties.begin() + vecSize);
		ComboDiscs.push_back(new Disc(tmpVector));
		offset = vecSize;
	}

}

ComboBox::~ComboBox()
{
	ComboDiscs.~vector();
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

int ComboBox::calcDiscVecSize(std::vector<std::string>& properties, int offset)
{
	int vecSize = offset + 1 + std::stoi(properties[offset]);
	int subNo = std::stoi(properties[vecSize]);
	vecSize += 1 + subNo;
	int bonNo = std::stoi(properties[vecSize]);
	vecSize += 1 + bonNo;
	return vecSize;
}