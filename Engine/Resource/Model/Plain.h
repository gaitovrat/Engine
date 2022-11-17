#pragma once

#include "Resource/DrawableObject.h"

class Plain final : public DrawableObject
{
public:
	Plain();

	Plain(Shader& shader);
};