#pragma once

#include <string>

struct IResource
{
	virtual void Load(std::string filepath) = 0;
};