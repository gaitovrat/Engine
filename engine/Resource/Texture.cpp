#include "Texture.hpp"

#include "GL/glew.h"
#include "SOIL/SOIL.h"

Texture::Texture() : m_id(-1)
{
}

Texture::Texture(const std::string filepath) : Texture()
{
	Load(filepath);
}

void Texture::Load(std::string filepath)
{
	m_id = SOIL_load_OGL_texture(filepath.c_str(), SOIL_LOAD_RGBA, SOIL_CREATE_NEW_ID, SOIL_FLAG_INVERT_Y);
}

void Texture::Bind() const
{
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_id);
}
