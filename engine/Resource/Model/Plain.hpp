#pragma once

#include "Resource/DrawableObject.hpp"

class Plain final : public DrawableObject
{
public:
	Plain();

	Plain(const std::shared_ptr<Shader>& shader);
};