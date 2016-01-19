#ifndef CALC_CPP
#define CALC_CPP

#include <exception>
#include <cmath>
#include "calculator.h"

Calculator::Calculator()
{
	Log = new SDI::Logger("ALL");
}

Calculator::~Calculator()
{
	Log->~Logger();
}

int Calculator::add(int lhs, int rhs)
{
	Log->log("IMFO", "Addition calculated");
	return lhs + rhs;
}

int Calculator::multiply(int lhs, int rhs)
{
	Log->log("IMFO", "Addition processed");
}

int Calculator::subtract(int lhs, int rhs)
{
	if (lhs < rhs)
	{
		Log->log("WARN", "Result will be negative");
	}
	Log->log("INFO", "Subraction calculated");
	return lhs - rhs;
}

int Calculator::divide(int lhs, int rhs)
{
	double result = 0;
	Log->log("IMFO", "Division processed");
	try
	{
		result = lhs / rhs;
		if (result - floor(result) != 0)
		{
			Log->log("WARN", "double to int possible loss of data");
		}
	}
	catch (std::exception& e)
	{
		Log->log("ERR", "Math Error: Result could be infinte");
	}
	return result;
}
#endif