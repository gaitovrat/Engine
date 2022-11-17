#pragma once

#include "Resource/DrawableObject.h"

class Gift final : public DrawableObject
{
public:
	Gift();

	Gift(Shader& shader);
};