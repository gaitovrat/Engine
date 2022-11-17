#include "Scene.hpp"

#include <iostream>

void Scene::AddObject(DrawableObject& object)
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
	auto& shader = object.GetShader();
	shader.SetLight(m_light);
	m_light.AddObserver(&shader);
	m_light.NotifyAll(LIGHT_POSITION_CHANGED);
}

std::vector<DrawableObject>& Scene::GetObjects()
{
	return m_objects;
}

DrawableObject& Scene::operator[](int index)
{
	return m_objects[index];
}

Light& Scene::GetLight()
{
	return m_light;
}
