#include "Scene.hpp"

Scene::Scene()
{
	m_skydome.GetTransformation().AddScale(glm::vec3(2, 2, 2));
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
	shader->SetLights(m_lights);

	for (const auto& light : m_lights)
	{
		light->AddObserver(shader);
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

Skydome& Scene::GetSkydome()
{
	return m_skydome;
}
