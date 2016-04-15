#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include "JSON\JSON.hpp"
using json = nlohmann::json;

class Material
{
public:
	Material(json properties);
	virtual ~Material() = 0;
	virtual json getProperties() = 0;

	int getId() const;
protected:
	int idNumber;
	std::string MaterialTitle;
	std::string format;
	std::string packagingSpec;
	double retailPrice;
};

#endif // !MATERIAL_H
