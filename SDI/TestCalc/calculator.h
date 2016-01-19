#ifndef CALC_H
#define CALC_H

#include "../Logger/logger.h"

class Calculator
{
public:
	Calculator();
	~Calculator();
	int add(int, int);
	int divide(int, int);
	int multiply(int, int);
	int subtract(int, int);
private:
	SDI::Logger* Log;
};


#endif 