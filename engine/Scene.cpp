#include "Scene.hpp"

void Scene::AddObject(DrawableObject* object)
{
	if (object == nullptr)
		return;

	m_objects.push_back(object);

	UpdateLastObject();
}

Scene::~Scene()
{
	for (const auto& light : m_lights)
	{
		delete light;
	}

	for (const auto& object : m_objects)
	{
		delete object;
	}
}

void Scene::UpdateObjects() const
{
	for (const auto& object : m_objects)
	{
		UpdateObject(object);
	}
}

void Scene::UpdateLastObject() const
{
	UpdateObject(m_objects.back());
}

void Scene::UpdateObject(DrawableObject* object) const
{
	auto& shader = object->GetShader();
	shader.SetLights(m_lights);

	for (const auto& light : m_lights)
	{
		light->AddObserver(&shader);
	}
}

std::vector<DrawableObject*>& Scene::GetObjects()
{
	return m_objects;
}

DrawableObject* Scene::operator[](const int index) const
{
	return m_objects[index];
}

std::vector<AbstractLight*>& Scene::GetLights()
{
	return m_lights;
}

void Scene::AddLight(AbstractLight* light)
{
	if (light == nullptr)
		return;

	m_lights.push_back(light);
	UpdateObjects();
}

SkyBox& Scene::GetSkyBox()
{
	return m_skyBox;
}
