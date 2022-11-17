#pragma once

#include "Resource/DrawableObject.h"

class Renderer
{
public:
	Renderer();

	void Clear();

	void Draw(DrawableObject& object);
};
