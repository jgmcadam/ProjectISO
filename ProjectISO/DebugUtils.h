#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>

#if !defined _ASSERTIONS_ENABLED && !defined _SLOW_ASSERTIONS_ENABLED
#define _ASSERTIONS_ENABLED 
#define _SLOW_ASSERTIONS_ENABLED
#endif // !_ASSERTIONS_ENABLED && _SLOW_ASSERTIONS_ENABLED

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

#ifdef _ASSERTIONS_ENABLED

#define ASSERT(expr, message) \
	if(expr) { } \
	else \
	{ \
		LogUtils::LogToDebug(#expr); \
		__debugbreak(); \
	} \

#else

#define ASSERT(expr) { }

#endif

#if defined _SLOW_ASSERTIONS_ENABLED && defined _DEBUG

#define SLOWASSERT(expr) \
	if(expr) { } \
	else \
	{ \
		LogUtils::LogToDebug(#expr); \
		__debugbreak(); \
	} \

#else

#define SLOWASSERT(expr) { }

#endif