#include "Texture.hpp"

#include "GL/glew.h"
#include "SOIL/SOIL.h"

#include <iostream>

Texture::Texture() : m_textureId(-1), m_isCubeMap(false)
{
}

Texture::Texture(const std::string filepath) : Texture()
{
	Load(filepath);
}

Texture::Texture(std::string x, std::string y, std::string z, std::string negx, std::string negy, std::string negz) : Texture()
{
	m_textureId = SOIL_load_OGL_cubemap(
		x.c_str(),
		negx.c_str(),
		y.c_str(),
		negy.c_str(),
		z.c_str(),
		negz.c_str(),
		SOIL_LOAD_RGB,
		SOIL_CREATE_NEW_ID,
		SOIL_FLAG_MIPMAPS
	);
	m_isCubeMap = true;

	std::cout << m_textureId << '\n';
}

void Texture::Load(const std::string& filepath)
{
	m_textureId = SOIL_load_OGL_texture(filepath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Texture::Bind() const
{
	auto target = GL_TEXTURE_2D;
	if (m_isCubeMap)
	{
		target = GL_TEXTURE_CUBE_MAP;
	}

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(target, m_textureId);
}
