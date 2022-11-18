#include "Log.hpp"

#include <chrono>
#include <iostream>
#include <format>

#include "Configuration.hpp"

static void print(const std::string& message)
{
	auto time = std::chrono::system_clock::now();
	std::cout << std::format("{:%X}", time) << ": " << message << std::endl;
}

void Log::info(const std::string message)
{
	if (Configuration::logLevel >= INFO)
	{
		std::cout << "[info] - ";
		print(message);
	}
}

void Log::debug(const std::string message)
{
	if (Configuration::logLevel >= DEBUG)
	std::cout << "[debug] - ";
	print(message);
}

