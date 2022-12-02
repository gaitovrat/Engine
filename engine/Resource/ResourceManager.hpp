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

	static ResourceManager& GetInstance();

	void AddShader(std::string name);

	std::shared_ptr<Shader> GetShader(std::string name);

	void AddTexture(std::string name);

	std::shared_ptr<Texture> GetTexture(std::string name);

	std::shared_ptr<DrawableObject> GetDrawableObject(std::string name, std::string shaderName, std::string textureName);

	void AddDrawableObject(std::string name, std::string shaderName, std::string textureName);

private:
	std::map<std::string, std::shared_ptr<IResource>> m_resources;
};
