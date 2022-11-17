#pragma once

#include "Resource/DrawableObject.hpp"

class Gift final : public DrawableObject
{
public:
	Gift();

	Gift(Shader& shader);
};
