#pragma once

#include "Resource/DrawableObject.h"

class Sphere final : public DrawableObject
{
public:
	Sphere();

	Sphere(Shader& shader);
};