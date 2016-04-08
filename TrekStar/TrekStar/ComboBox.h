#ifndef COMBOBOX_H
#define COMBOBOX_H

#include <vector>
#include "Material.h"
#include "Disc.h"

class ComboBox :
	public Material
{
public:
	ComboBox(json properties);
	~ComboBox();
	json getProperties();
private:
	std::vector<Disc*> ComboDiscs;
};

#endif //COMBOBOX_H