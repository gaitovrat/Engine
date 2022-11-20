#include "Log.hpp"

#include <iostream>

static void print(const std::string& message)
{
	std::cout << message << std::endl;
}

void Log::info(const std::string message)
{
	std::cout << "[info] - ";
	print(message);
}

void Log::debug(const std::string message)
{
#ifndef NDEBUG
	std::cout << "[debug] - ";
	print(message);
#endif
}

