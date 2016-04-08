#include "Disc.h"



Disc::Disc(std::vector<std::string>& properties) : Material(properties)
{
	int langNo = std::stoi(properties[6]);
	for (int i = 0; i < langNo; i++)
	{
		if (i > 0) language.push_back(properties[6 + i]);
	}

	int vecPos = 7 + langNo;
	int subNo = std::stoi(properties[vecPos]);

	for (int i = 0; i < subNo; i++)
	{
		if (i > 0) subLanguage.push_back(properties[vecPos + i]);
	}

	vecPos += 1 + subNo;
	int bonNo = std::stoi(properties[vecPos]);

	for (int i = 0; i < bonNo; i++)
	{
		if (i > 0) bonusFeatures.push_back(properties[vecPos + i]);
	}

	vecPos += 1 + bonNo;

	audioFormat = properties[vecPos];
	frameAspect = properties[vecPos + 1];
	runtime = std::stoi(properties[vecPos + 2]);
}

Disc::~Disc()
{
}

std::vector<std::string> Disc::getProperties()
{
	std::vector<std::string> tmp;
	tmp.push_back("Disc");
	tmp.push_back(std::to_string(idNumber));
	tmp.push_back(MaterialTitle);
	tmp.push_back(format);
	tmp.push_back(packagingSpec);
	tmp.push_back(std::to_string(retailPrice));
	
	tmp.push_back(std::to_string(language.size()));
	for (std::vector<std::string>::iterator it = language.begin(); 
		it != language.end(); it++)
		tmp.push_back(*it);

	tmp.push_back(std::to_string(subLanguage.size()));
	for (std::vector<std::string>::iterator it = subLanguage.begin();
		it != subLanguage.end(); it++)
		tmp.push_back(*it);

	tmp.push_back(audioFormat);
	tmp.push_back(frameAspect);
	tmp.push_back(std::to_string(runtime));

	return tmp;
}

int Disc::calcDiscVecSize(std::vector<std::string>& properties, int offset)
{
	int vecSize = offset + 1 + std::stoi(properties[offset]);
	int subNo = std::stoi(properties[vecSize]);
	vecSize += 1 + subNo;
	int bonNo = std::stoi(properties[vecSize]);
	vecSize += 1 + bonNo;
	return vecSize;
}