#ifndef MATERIAL_CPP
#define MATERIAL_CPP

#include <fstream>
#include <vector>
#include <cassert>

#include "Material.h"

using namespace std;
using json = nlohmann::json;

Material::Material(json properties)
{
	assert(properties.is_null() && !properties.is_object() && " JSON invalid. Must be JSON object.");
	idNumber = properties["ID"].get<int>();
	projIdNumber = properties["Project ID"];
	MaterialTitle = properties["Material Title"].get<string>();
	format = properties["Format"].get<string>();
	packagingSpec = properties["Packaging Specification"].get<string>();
	retailPrice = properties["Retail Price"].get<double>();
}

Material::~Material() {}

json Material::getProperties()
{
	json tmp;
	tmp["ID"] = idNumber;
	tmp["Material Title"] = MaterialTitle;
	tmp["Format"] = format;
	tmp["Packaging Specification"] = packagingSpec;
	tmp["Retail Price"] = retailPrice;
	return tmp;
}

int Material::getId() const
{
	return idNumber;
}

int Material::getProjId() const
{
	return projIdNumber;
}
#endif // !MATERIAL_CPP