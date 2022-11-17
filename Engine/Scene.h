#pragma once

#include <vector>

#include "Resource/DrawableObject.h"
#include "Camera.h"
#include "Light.h"

class Scene final
{
public:
	void AddObject(DrawableObject& object);

	void UpdateObjects();

	std::vector<DrawableObject>& GetObjects();

	DrawableObject& operator[](int index);

	Light& GetLight();

private:
	void UpdateLastObject();
	void UpdateObject(DrawableObject& object);

	std::vector<DrawableObject> m_objects;
	Light m_light;
};
