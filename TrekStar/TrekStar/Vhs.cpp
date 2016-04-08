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
	std::vector<std::string> tmp;
	tmp = Material::getProperties();
	tmp.push_back("VHS");
	tmp.push_back(std::to_string(idNumber));
	tmp.push_back(MaterialTitle);
	tmp.push_back(format);
	tmp.push_back(packagingSpec);
	tmp.push_back(std::to_string(retailPrice));
	tmp.push_back(language);
	tmp.push_back(subLanguage);
	tmp.push_back(audioFormat);
	tmp.push_back(frameAspect);
	tmp.push_back(std::to_string(runtime));

	return tmp;
}