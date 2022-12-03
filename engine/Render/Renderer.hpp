#pragma once

#include "Resource/DrawableObject.hpp"
#include "Resource/SkyBox.hpp"

class Renderer
{
public:
	void Clear();

	void Draw(DrawableObject& object);

	void Draw(SkyBox& skyBox);
};
