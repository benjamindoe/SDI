#ifndef DISC_H
#define DISC_H

#include <vector>
#include "Material.h"

using namespace std;

class Disc :
	public Material
{
public:
	Disc(json properties);
	~Disc();
	json getProperties();
protected:
	vector<string> language;
	vector<string> subLanguage;
	vector<string> bonusFeatures; // Could be expanded to have it's own class.
	string audioFormat;
	string frameAspect;
	int runtime;

};

#endif //DISC_H