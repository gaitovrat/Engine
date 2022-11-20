#include "ResourceManager.hpp"

#include <ranges>

ResourceManager::ResourceManager()
{
	for (std::string names[] = {
		     "lights"
	     }; const auto& name : names)
	{
		AddShader(name);
	}
}

ResourceManager::~ResourceManager()
{
	for (const auto& val : m_shaders | std::views::values)
	{
		delete val;
	}
}

ResourceManager& ResourceManager::GetInstance()
{
	static ResourceManager instance;

	return instance;
}

void ResourceManager::AddShader(const std::string name)
{

	m_shaders[name] = new Shader("assets/shader/" + name);

	Link(name);
}

Shader& ResourceManager::GetShader(const std::string name)
{
	return *m_shaders[name];
}

std::map<std::string, Shader*>& ResourceManager::GetShaders()
{
	return m_shaders;
}

void ResourceManager::Link(const std::string name)
{
	m_shaders[name]->Link();
}
