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

std::string ResourceManager::TextureName(const std::string& name)
{
	return "texture." + name;
}

std::string ResourceManager::ShaderName(const std::string& name)
{
	return "shader." + name;
}

std::string ResourceManager::DrawableObjectName(const std::string& name)
{
	return "object." + name;
}

ResourceManager& ResourceManager::GetInstance()
{
	static ResourceManager instance;

	return instance;
}

void ResourceManager::AddShader(const std::string name)
{
	const auto shader = std::make_shared<Shader>("assets/shader/" + name);

	shader->Link();
	m_resources[ShaderName(name)] = shader;
}

std::shared_ptr<Shader> ResourceManager::GetShader(const std::string name)
{
	if (!m_resources.contains(ShaderName(name)))
	{
		AddShader(name);
	}

	return std::dynamic_pointer_cast<Shader>(m_resources[ShaderName(name)]);
}

void ResourceManager::AddTexture(const std::string name)
{
	m_resources[TextureName(name)] = std::make_shared<Texture>("assets/texture/" + name);
}

std::shared_ptr<Texture> ResourceManager::GetTexture(const std::string name)
{
	if (!m_resources.contains(TextureName(name)))
	{
		AddTexture(name);
	}

	return std::dynamic_pointer_cast<Texture>(m_resources[TextureName(name)]);
}

std::shared_ptr<DrawableObject> ResourceManager::GetDrawableObject(const std::string name, const std::string shaderName, const std::string textureName)
{
	auto shader = GetShader(shaderName);
	auto texture = GetTexture(textureName);

	if (!m_resources.contains(DrawableObjectName(name)))
	{
		AddDrawableObject(name, shaderName, textureName);
	}

	auto object = std::dynamic_pointer_cast<DrawableObject>(m_resources[DrawableObjectName(name)]);
	object->SetShader(shader);
	object->SetTexture(*texture);

	return object;
}

void ResourceManager::AddDrawableObject(const std::string name, const std::string shaderName, const std::string textureName)
{
	m_resources[DrawableObjectName(name)] = std::make_shared<DrawableObject>("assets/mesh/" + name, GetShader(shaderName), *GetTexture(textureName));
}
