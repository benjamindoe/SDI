#ifndef DOUBLE_SIDED_DVD_H
#define DOUBLE_SIDED_DVD_H

#include "Disc.h"

class DoubleSidedDvd :
	public Disc
{
public:
	DoubleSidedDvd();
	DoubleSidedDvd(std::vector<std::string>&properties);
	~DoubleSidedDvd();
	void setProperties(std::vector<std::string>& properties);
	std::vector<std::string> getProperties();
private:
	Disc* sideA;
	Disc* sideB;
};

#endif //DOUBLE_SIDED_DVD_H