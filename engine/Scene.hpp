#pragma once

#include <vector>

#include "Resource/DrawableObject.hpp"
#include "Light/AbstractLight.hpp"
#include "Resource/Skydome.hpp"

class Scene final
{
public:
	Scene();

	void AddObject(DrawableObject* object);

	~Scene();

	void UpdateObjects() const;

	std::vector<DrawableObject*>& GetObjects();

	DrawableObject* operator[](int index) const;

	std::vector<AbstractLight*>& GetLights();
	void AddLight(AbstractLight* light);

	[[nodiscard]] Skydome& GetSkydome();

private:
	void UpdateLastObject() const;
	void UpdateObject(DrawableObject* object) const;

	std::vector<DrawableObject*> m_objects;
	std::vector<AbstractLight*> m_lights;
	Skydome m_skydome;
};
