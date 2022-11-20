#pragma once

#include "IResource.hpp"

class Texture final : public IResource
{
public:
	void Load(std::string filepath) override;

	virtual ~Texture() = default;
};