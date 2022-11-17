#pragma once

#include "Resource/DrawableObject.hpp"

class Renderer
{
public:
	Renderer();

	void Clear();

	void Draw(DrawableObject& object);
};
