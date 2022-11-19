#pragma once

#include <string>
#include "Log/ELogLevel.hpp"

struct Configuration
{
	static float playerSpeed;
	static float sensivity;
	static float level;
	static ELogLevel logLevel;
	static std::string defaultShader;
};
