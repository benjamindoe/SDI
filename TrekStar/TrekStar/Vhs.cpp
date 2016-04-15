#ifndef VHS_CPP
#define VHS_CPP

#include "Vhs.h"

Vhs::Vhs(json properties) : Material(properties)
{
	language = properties["Language"].get<string>();
	subLanguage = properties["Subtitle Language"].get<string>();
	audioFormat = properties["Audio Format"].get<string>();
	frameAspect = properties["Frame Aspect"].get<string>();
	runtime = properties["Runtime"].get<int>();
}


Vhs::~Vhs()
{
}

json Vhs::getProperties()
{
	json tmp = Material::getProperties();
	tmp["Language"] = language;
	tmp["Subtitle Language"] = subLanguage;
	tmp["Frame Aspect"] = frameAspect;
	tmp["Runtime"] = runtime;

	return tmp;
}

#endif // !VHS_CPP
