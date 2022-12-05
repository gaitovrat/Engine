#pragma once

#include "Resource/DrawableObject.hpp"

class SuziFlat final : public DrawableObject
{
public:
	SuziFlat();

	SuziFlat(const std::shared_ptr<Shader>& shader);
};