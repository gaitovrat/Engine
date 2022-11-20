#pragma once

#include <map>
#include <string>

#include "Shader.hpp"
#include "IResource.hpp"
#include "Texture.hpp"
#include "DrawableObject.hpp"

class ResourceManager final
{
	ResourceManager();

	static std::string TextureName(const std::string& name);

	static std::string ShaderName(const std::string& name);

	static std::string DrawableObjectName(const std::string& name);

public:
	~ResourceManager();

	static ResourceManager& GetInstance();

	void AddShader(std::string name);

	Shader& GetShader(std::string name);

	void AddTexture(std::string name);

	Texture& GetTexture(std::string name);

	DrawableObject& GetDrawableObject(std::string name, std::string shaderName, std::string textureName);

	void AddDrawableObject(std::string name, std::string shaderName, std::string textureName);

private:
	std::map<std::string, IResource*> m_resources;
};
