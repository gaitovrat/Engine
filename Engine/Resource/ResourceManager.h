#pragma once

#include <map>
#include <string>

#include "Shader.h"
#include "Camera.h"

class ResourceManager final
{
private:
	ResourceManager();

public:
	~ResourceManager();

	static ResourceManager& GetInstance();

	void AddShader(std::string name);

	Shader& GetShader(std::string name);

	std::map<std::string, Shader*>& GetShaders();

private:
	void Link(std::string name);

	std::map<std::string, Shader*> m_shaders;
};
