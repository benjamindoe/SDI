#ifndef DISC_H
#define DISC_H

#include <vector>
#include "Material.h"

class Disc :
	public Material
{
public:
	Disc(json properties);
	~Disc();
	json getProperties();
protected:
	std::vector<std::string> language;
	std::vector<std::string> subLanguage;
	std::vector<std::string> bonusFeatures;
	std::string audioFormat;
	std::string frameAspect;
	int runtime;

};

#endif //DISC_H