#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <vector>
#include "Material.h"
#include "Disc.h"

class ComboBox :
	public Material
{
public:
	ComboBox(std::vector<std::string>& properties);
	~ComboBox();
	std::vector<std::string> getProperties();
private:
	int calcDiscVecSize(std::vector<std::string>& properties, int offset);
	std::vector<Disc*> ComboDiscs;
};

#endif //COMBOBOX_H