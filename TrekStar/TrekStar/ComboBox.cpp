#ifndef COMBOBOX_CPP
#define COMBOBOX_CPP

#include "ComboBox.h"

using json = nlohmann::json;
using namespace std;

ComboBox::ComboBox(json properties) : Material(properties)
{
	for (int i = 0; i < properties["Discs"].size(); i++)
	{
		Disc* tmpDisc = new Disc(properties["Discs"].at(i));
		ComboDiscs.push_back(tmpDisc);
	}
}

ComboBox::~ComboBox()
{
	ComboDiscs.~vector();
}

json ComboBox::getProperties()
{
	json tmp = Material::getProperties();
	tmp["Discs"] = {};
	for (Disc* disc : ComboDiscs)
		tmp["Discs"].push_back(disc);

	return tmp;
}


#endif // !COMBOBOX_CPP