#include "BaseShader.h"

#include <GL/glew.h>

#include "Util/FileUtil.h"
#include "Exception/GLException.h"

BaseShader::BaseShader(const char* filename, const EShaderType type) : m_id(0)
{
	auto shader = FileUtil::Read(filename);
	auto shader_c = shader.c_str();

	m_id = glCreateShader(type);
	glShaderSource(m_id, 1, &shader_c, nullptr);
}

void BaseShader::Compile() const
{
	int status;

	glCompileShader(m_id);
	glGetShaderiv(m_id, GL_COMPILE_STATUS, &status);

	if (status == false)
	{
		throw GLException("Shader compilation error - " + ShaderUtil::GetInfo(m_id));
	}
}

void BaseShader::AttachToProgram(const uint32_t programId) const
{
	glAttachShader(programId, m_id);
}
