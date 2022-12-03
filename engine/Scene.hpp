#pragma once

#include <vector>

#include "Resource/DrawableObject.hpp"
#include "Light/AbstractLight.hpp"
#ifdef SKYBOX
#include "Resource/SkyBox.hpp"
#else
#include "Resource/Skydome.hpp"
#endif

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

#ifdef SKYBOX
	_NODISCARD SkyBox& GetSky();
#else
	_NODISCARD Skydome& GetSky();
#endif

private:
	void UpdateLastObject();

	void UpdateObject(DrawableObject& object);

	std::vector<DrawableObject> m_objects;
	std::vector<std::shared_ptr<AbstractLight>> m_lights;
#ifdef SKYBOX
	SkyBox m_sky;
#else
	Skydome m_sky;
#endif
};
