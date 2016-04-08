#ifndef VHS_H
#define VHS_H

#include "Material.h"

using namespace std;

class Vhs :
	public Material
{
public:
	Vhs(json properties);
	~Vhs();
	json getProperties();
private:
	string language;
	string subLanguage;
	string audioFormat;
	string frameAspect;
	int runtime;
};

#endif //VHS_H
