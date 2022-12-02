#pragma once

#include <string>

struct IResource
{
	virtual void Load(const std::string& filepath) = 0;
};