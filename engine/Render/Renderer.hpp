#pragma once

#include "Resource/DrawableObject.hpp"
#include "Resource/SkyBox.hpp"

class Renderer
{
public:
	Renderer();

	void Clear();

	void Draw(DrawableObject& object);

	void Draw(SkyBox& skyBox);
};
