#ifndef VHS_H
#define VHS_H

#include <string>
#include "Material.h"

class Vhs :
	public Material
{
public:
	Vhs(std::vector<std::string>& properties);
	~Vhs();
	std::vector<std::string> getProperties();
private:
	std::string language;
	std::string subLanguage;
	std::string audioFormat;
	std::string frameAspect;
	int runtime;
};

#endif //VHS_H
