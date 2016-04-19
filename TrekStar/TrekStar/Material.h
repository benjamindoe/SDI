#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

#include "JSON\JSON.hpp"
typedef nlohmann::json json;

class Material
{
public:
	Material(json properties);
	virtual ~Material() = 0;
	virtual json getProperties() = 0;

	int getId() const;
	int getProjId() const;
protected:
	int idNumber;
	int projIdNumber;
	std::string MaterialTitle;
	std::string format;
	std::string packagingSpec;
	double retailPrice;
};

#endif // !MATERIAL_H
