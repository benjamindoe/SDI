#include <fstream>
#include <vector>
#include "Material.h"

Material::Material(std::vector<std::string>& properties)
{
	format = properties[0];
	idNumber = std::stoi(properties[1]);
	MaterialTitle = properties[2];
	packagingSpec = properties[3];
	relatedProject = properties[4];
	retailPrice = std::stoi(properties[5]);
}