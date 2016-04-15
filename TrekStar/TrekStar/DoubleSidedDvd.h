#ifndef DOUBLE_SIDED_DVD_H
#define DOUBLE_SIDED_DVD_H

#include "Disc.h"

class DoubleSidedDvd :
	public Disc
{
public:
	DoubleSidedDvd(json properties);
	~DoubleSidedDvd();
	json getProperties();
private:
	Disc* sideA;
	Disc* sideB;
};

#endif // !DOUBLE_SIDED_DVD_H