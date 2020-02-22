#pragma once

#include <iostream>
#include <fstream>
#include <string>

class LogUtils final
{

public:

	static void InitDebug(std::string message);
	static void LogToDebug(std::string message);

private:

	static void LogTimeToStream(std::ostream & stream);
	static void LogDebugMessageToStream(std::ostream & stream, std::string message);

private:

	static const std::string logFileLocation;

};