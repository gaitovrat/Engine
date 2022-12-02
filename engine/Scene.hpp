#pragma once

#include <vector>

#include "Resource/DrawableObject.hpp"
#include "Light/AbstractLight.hpp"
#include "Resource/Skydome.hpp"

class Scene final
{
public:
	Scene();

	void AddObject(const DrawableObject& object);

	~Scene() = default;

	void UpdateObjects();

	std::vector<DrawableObject>& GetObjects();

	DrawableObject& operator[](int index);

	std::vector<std::shared_ptr<AbstractLight>>& GetLights();

	void AddLight(const std::shared_ptr<AbstractLight>& light);

	[[nodiscard]] Skydome& GetSkydome();

private:
	void UpdateLastObject();

	void UpdateObject(DrawableObject& object);

	std::vector<DrawableObject> m_objects;
	std::vector<std::shared_ptr<AbstractLight>> m_lights;
	Skydome m_skydome;
};
