#pragma once

#include "Resource/DrawableObject.hpp"

class SuziSmooth final : public DrawableObject
{
public:
	SuziSmooth();

	SuziSmooth(const std::shared_ptr<Shader>& shader);
};