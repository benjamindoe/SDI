#ifndef DISC_H
#define DISC_H

#include <vector>
#include "Material.h"

class Disc :
	public Material
{
public:
	Disc();
	Disc(std::vector<std::string>& properties);
	~Disc();
	void setProperties(std::vector<std::string>& properties);
	std::vector<std::string> getProperties();
protected:
	int calcDiscVecSize(std::vector<std::string>& properties, int offset);
	std::vector<std::string> language;
	std::vector<std::string> subLanguage;
	std::vector<std::string> bonusFeatures;
	std::string audioFormat;
	std::string frameAspect;
	int runtime;

};

#endif //DISC_H