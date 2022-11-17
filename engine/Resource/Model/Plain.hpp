#pragma once

#include "Resource/DrawableObject.hpp"

class Plain final : public DrawableObject
{
public:
	Plain();

	Plain(Shader& shader);
};
