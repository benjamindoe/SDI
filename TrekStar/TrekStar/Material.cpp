#include <fstream>
#include <vector>
#include <cassert>

#include "Material.h"

using namespace std;

Material::Material(json properties)
{
	assert(properties.is_null() && !properties.is_object() && " JSON invalid. Must be JSON object.");
	idNumber = properties["ID"].get<int>();
	MaterialTitle = properties["Material Title"].get<string>();
	format = properties["Format"].get<string>();
	packagingSpec = properties["Packaging Specification"].get<string>();
	retailPrice = properties["Retail Price"].get<double>();
}

Material::~Material() {}

json Material::getProperties()
{

}