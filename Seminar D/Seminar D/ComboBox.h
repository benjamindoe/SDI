#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <vector>
#include "Material.h"
#include "Disc.h"

class ComboBox :
	public Material
{
public:
	ComboBox();
	~ComboBox();
	void setProperties(std::vector<std::string>& attribs);
	std::vector<std::string> getProperties();
private:
	std::vector<Disc*> ComboDiscs;
};

#endif //COMBOBOX_H