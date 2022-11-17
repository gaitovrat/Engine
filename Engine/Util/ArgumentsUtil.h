#pragma once

#include <map>
#include <string>

class ArgumentsUtil
{
public:
	static void Parse(int argc, const char** argv, int& width, int& height);
};