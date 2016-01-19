#ifndef LOGGER_H
#define LOGGER_H

#include <utility>
#include <string>
#include <fstream>
#include <map>

#include "../DynArray/DynArray.cpp"

namespace SDI 
{
	typedef std::string logType;
	typedef std::string logLvl;
	typedef DynArray<std::string> bufferType;
	class Logger
	{
	private:
		Logger();
		bufferType buffer_ = bufferType(3);
		const logLvl logLvls[4] = { "NONE", "WARN", "ERR", "ALL" };
		const logType logTypes[3] = { "WARN", "ERR", "INFO" };
		int lvl;
		std::ofstream logFile;
		std::string getTimestamp(std::string timeFormat = "%d-%m-%Y %H:%M:%S");
		void fileOpen();
	public:
		Logger(const logLvl);
		Logger(int argc, char* argv[]);
		~Logger();

		void log(const logType type, const std::string logText, std::string timeFormat = "%d-%m-%Y %H:%M:%S");
		void setLevel(logLvl);
		void printSessionLogs();
		DynArray<std::string> getSessionLogs();
		std::string getLevel();

	};
}

#endif


