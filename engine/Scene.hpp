#pragma once

#include <vector>

#include "Resource/DrawableObject.hpp"
#include "Light/AbstractLight.hpp"

class Scene final
{
public:
	void AddObject(DrawableObject* object);

	~Scene();

	void UpdateObjects() const;

	std::vector<DrawableObject*>& GetObjects();

	DrawableObject* operator[](int index) const;

	std::vector<AbstractLight*>& GetLights();
	void AddLight(AbstractLight* light);

private:
	void UpdateLastObject() const;
	void UpdateObject(DrawableObject* object) const;

	std::vector<DrawableObject*> m_objects;
	std::vector<AbstractLight*> m_lights;
};
