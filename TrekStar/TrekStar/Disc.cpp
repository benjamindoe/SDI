#ifndef DISC_CPP
#define DISC_CPP

#include "Disc.h"

Disc::Disc(json properties) : Material(properties)
{
	language = properties["Language"].get<vector<string>>();
	subLanguage = properties["Subtitle Language"].get<vector<string>>();
	bonusFeatures = properties["Bonus Features"].get<vector<string>>();
	audioFormat = properties["Audio Format"].get<string>();
	frameAspect = properties["Frame Aspect"].get<string>();
	runtime = properties["Runtime"].get<int>();
}

Disc::~Disc()
{
}

json Disc::getProperties()
{
	json tmp = Material::getProperties;
	tmp["Language"] = language;
	tmp["Subtitle Lanugage"] = subLanguage;
	tmp["Bonus Features"] = bonusFeatures;
	tmp["Audio Format"] = audioFormat;
	tmp["Frame Aspect"] = frameAspect;
	tmp["Runtime"] = runtime;

	return tmp;
}

#endif // !DISC_CPP