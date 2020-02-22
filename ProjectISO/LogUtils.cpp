#include "LogUtils.h"

std::string const LogUtils::logFileLocation = "log.txt";

void LogUtils::InitDebug(std::string message)
{
#ifndef _DEBUG
	std::ofstream logFile;
	logFile.open(logFileLocation.c_str(), std::ios::out | std::ios::trunc);
	LogDebugMessageToStream(logFile, message);
	logFile.close();
#else
	LogDebugMessageToStream(std::cout, message);
#endif
}

void LogUtils::LogToDebug(std::string message)
{
#ifndef _DEBUG
	std::ofstream logFile;
	logFile.open(logFileLocation.c_str(), std::ios::out | std::ios::app);
	LogTimeToStream(logFile);
	LogDebugMessageToStream(logFile, message);
	logFile.close();
#else
	LogTimeToStream(std::cout);
	LogDebugMessageToStream(std::cout, message);
#endif
}

void LogUtils::LogDebugMessageToStream(std::ostream & stream, std::string message)
{
	stream << "Log: File: " << __FILE__ << ", Line: " << __LINE__ << ": " << message << std::endl;
}

void LogUtils::LogTimeToStream(std::ostream & stream)
{
	stream << "Time: " << __TIME__ << ": ";
}
