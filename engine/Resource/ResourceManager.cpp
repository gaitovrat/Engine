#include "ResourceManager.hpp"

ResourceManager::ResourceManager()
{
	std::string names[] = {
		"1",
		"2.1",
		"2.2",
		"3.1",
		"3.2",
		"3.3"
	};
	for (const auto& name : names)
	{
		AddShader(name);
	}
}

ResourceManager::~ResourceManager()
{
	for (const auto& pair : m_shaders)
	{
		delete pair.second;
	}
}

ResourceManager& ResourceManager::GetInstance()
{
	static ResourceManager instance;

	return instance;
}

void ResourceManager::AddShader(std::string name)
{
	std::string nameDirectory = "assets/" + name;
	std::string vertex = nameDirectory + ".vert";
	std::string fragment = nameDirectory + ".frag";

	const char* cvertex = vertex.c_str();
	const char* cfragment = fragment.c_str();

	m_shaders[name] = new Shader(cvertex, cfragment);

	Link(name);
}

Shader& ResourceManager::GetShader(std::string name)
{
	return *m_shaders[name];
}

std::map<std::string, Shader*>& ResourceManager::GetShaders()
{
	return m_shaders;
}

void ResourceManager::Link(std::string name)
{
	m_shaders[name]->Link();
}
