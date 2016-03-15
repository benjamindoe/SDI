#pragma once
#ifndef MATERIAL_H
#define MATERIAL_H

#include <string>
#include <vector>

class Material
{
public:
	Material(std::vector<std::string>& properties);
	virtual std::vector<std::string> getProperties() = 0;
protected:
	int idNumber;
	std::string MaterialTitle;
	std::string format;
	std::string packagingSpec;
	std::string relatedProject;
	double retailPrice;
};

#endif //MATERIAL_H
