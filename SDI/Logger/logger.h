#ifndef LOGGER_H
#define LOGGER_H

#include <string>

#include "../DynArray/DynArray.h"

namespace SDI 
{
	class Logger
	{
	private:
		DynArray<std::string> loggerArray(10);
	public:
		Logger();
		~Logger();
	};
}

#endif