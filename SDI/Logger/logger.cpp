#ifndef LOGGER_CPP
#define LOGGER_CPP

#include <cassert>
#include <functional>
#include <ctime>
#include <iostream>
#include "../CLargs/CLargs.cpp"

#include "logger.h"

namespace SDI
{
	Logger::Logger() {}

	Logger::Logger(logLvl usrLvl)
	{
		setLevel(usrLvl);
		fileOpen();
	}
	Logger::Logger(int argc, char * argv[])
	{
		std::map<char, std::string> flags = parseArgsValues(argc, argv);
		if (flags.find('l') != flags.end())
		{
			setLevel(flags.at('l'));
		}
		else
		{
			lvl = 0;
		}
		fileOpen();
	}

	Logger::~Logger()
	{
		buffer_.~DynArray();
		logFile.close();
	}

	std::string Logger::getTimestamp(std::string timeFormat)
	{
		time_t  rawTime;
		struct tm formatedTime;
		char timeBuffer[50];

		time(&rawTime);
		localtime_s(&formatedTime, &rawTime);
		strftime(timeBuffer, 50, timeFormat.c_str(), &formatedTime);
		return std::string(timeBuffer);

	}
	void Logger::log(const logType type, const std::string logText, std::string timeFormat)
	{
		assert(std::find(logTypes, logTypes + sizeof(logTypes) / sizeof(*logTypes), type));
		if ( type == "ERR" && lvl >= 2 || type == "WARN" && lvl >= 1 || type == "INFO" && lvl >= 3)
		{
			std::string logString;
			logString = "[" + getTimestamp(timeFormat) + "] ";
			logString += type + ": " + logText;
			buffer_.push_back(logText);
			if(logFile.is_open())
			logFile << logText << std::endl;
		}
	}

	void Logger::fileOpen()
	{
		std::string fileName = "log " + getTimestamp("%d-%m-%Y %H-%M-%S") + ".log";
		logFile.open(fileName, std::ios::out | std::ios::app);
	}

	void Logger::setLevel(logLvl newLvl)
	{
		const std::string * findLvl = std::find(logLvls, logLvls + sizeof(logLvls) / sizeof(*logLvls), newLvl);
		assert(findLvl);
		lvl = findLvl - logLvls;
	}

	void Logger::printSessionLogs()
	{
		for (int i = 0; i < buffer_.size(); i++)
		{
			std::cout << buffer_[i] << std::endl;
		}
	}

	DynArray<std::string> Logger::getSessionLogs()
	{
		return buffer_;
	}

	std::string Logger::getLevel()
	{
		return logLvls[lvl];
	}
}

#endif