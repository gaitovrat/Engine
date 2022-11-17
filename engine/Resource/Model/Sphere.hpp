#pragma once

#include "Resource/DrawableObject.hpp"

class Sphere final : public DrawableObject
{
public:
	Sphere();

	Sphere(Shader& shader);
};
