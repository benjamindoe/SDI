#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

class Material
{
public:

	virtual void setProperties(std::vector<std::string>& properties) = 0;
	virtual std::vector<std::string> getProperties() = 0;
protected:
	int idNumber;
	std::string MaterialTitle;
	std::string format;
	std::string packagingSpec;
	double retailPrice;
};

#endif //MATERIAL_H
