#include "Scene.hpp"

Scene::Scene() : Scene(true)
{
}

Scene::Scene(bool withSkybox) : m_sky(decltype(m_sky){})
{
	if (withSkybox) 
	{
		m_sky = decltype(m_sky)(SkyBox());
	}
}

void Scene::AddObject(const DrawableObject& object)
{
	m_objects.push_back(object);

	UpdateLastObject();
}

void Scene::UpdateObjects()
{
	for (auto& object : m_objects)
	{
		UpdateObject(object);
	}
}

void Scene::UpdateLastObject()
{
	UpdateObject(m_objects.back());
}

void Scene::UpdateObject(DrawableObject& object)
{
	auto shader = object.GetShader();
	if (auto shaderLock = shader.lock())
	{
		if (m_lights.size() != 0)
		{
			shaderLock->SetLights(m_lights);
		}

		for (const auto& light : m_lights)
		{
			light->AddObserver(shaderLock.get());
		}
	}
}

std::vector<DrawableObject>& Scene::GetObjects()
{
	return m_objects;
}

DrawableObject& Scene::operator[](const int index)
{
	return m_objects[index];
}

std::vector<std::shared_ptr<AbstractLight>>& Scene::GetLights()
{
	return m_lights;
}

void Scene::AddLight(const std::shared_ptr<AbstractLight>& light)
{
	m_lights.push_back(light);
	UpdateObjects();
}

std::optional<SkyBox>& Scene::GetSky()
{
	return m_sky;
}
