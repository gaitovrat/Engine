#pragma once

#include "Resource/DrawableObject.hpp"

class Sphere final : public DrawableObject
{
public:
	Sphere();

	Sphere(const std::shared_ptr<Shader>& shader);
};