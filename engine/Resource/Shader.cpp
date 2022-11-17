#include "Resource/Shader.hpp"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <glm/gtx/string_cast.hpp>

#include "Exception/GLException.hpp"

#include "Camera.hpp"
#include "Light.hpp"

Shader::Shader() : m_id(0), m_modelId(0), m_projectionId(0), m_viewId(0), m_shaders(), m_modelMatrix(1.f), m_projectionMatrix(1.f), m_viewMatrix(1.f),
	m_lightId(0), m_lightPosition(0), m_light(nullptr), m_eyeId(0)
{
	m_id = glCreateProgram();

	auto& camera = Camera::GetInstance();
    camera.AddObserver(this);
	m_viewMatrix = camera.ToMatrix();
	SetProjectionMatrix(camera.GetWidth(), camera.GetHeight());
}

Shader::Shader(const VertexShader& vertexShader, const FragmentShader& fragmentShader) : Shader()
{
	m_shaders.push_back(vertexShader);
	m_shaders.push_back(fragmentShader);
}

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) : Shader()
{
	m_shaders.emplace_back(vertexShaderSource, VERTEX);
	m_shaders.emplace_back(fragmentShaderSource, FRAGMENT);
}

Shader::Shader(const VertexShader& vertexShader, const FragmentShader& fragmentShader, Light& light) : Shader(vertexShader, fragmentShader)
{
	light.AddObserver(this);
	m_light = &light;
}

void Shader::Link()
{
	for (const auto& shader : m_shaders)
	{
		shader.Compile();
		shader.AttachToProgram(m_id);
	}

	glLinkProgram(m_id);

	int32_t status;
	glGetProgramiv(m_id, GL_LINK_STATUS, &status);
	if (false == status)
	{
		std::string info = ShaderUtil::GetInfo(m_id);
		throw GLException("Unable to link program - " + ShaderUtil::GetInfo(m_id));
	}

	m_modelId = glGetUniformLocation(m_id, "model");
	m_projectionId = glGetUniformLocation(m_id, "projection");
	m_viewId = glGetUniformLocation(m_id, "view");
	m_eyeId = glGetUniformLocation(m_id, "eye");
	m_lightId = glGetUniformLocation(m_id, "light");
}

void Shader::Activate() const
{
	glUseProgram(m_id);
}	

void Shader::SetModelMatrix(const glm::mat4 modelMatrix)
{
	m_modelMatrix = modelMatrix;
}

void Shader::SetProjectionMatrix(const int width, const int height)
{
	m_projectionMatrix = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.1f, 100.0f);
}

void Shader::SetLight(Light& light)
{
	if (m_light == &light)
	{
		return;
	}

	m_light = &light;
}

void Shader::UpdateUniforms() const
{
	glUniformMatrix4fv(m_viewId, 1, GL_FALSE, glm::value_ptr(m_viewMatrix));
	glUniformMatrix4fv(m_projectionId, 1, GL_FALSE, glm::value_ptr(m_projectionMatrix));
	glUniformMatrix4fv(m_modelId, 1, GL_FALSE, glm::value_ptr(m_modelMatrix));
	glUniform3fv(m_eyeId, 1, glm::value_ptr(Camera::GetInstance().GetEye()));
	glUniform3fv(m_lightId, 1, glm::value_ptr(m_lightPosition));
}

void Shader::Notify(EObserverEvent event)
{
	auto& camera = Camera::GetInstance();

    switch (event)
    {
        case VIEW_MATRIX_CHANGED:
            m_viewMatrix = camera.ToMatrix();
            break;
        case PROJECTION_MATRIX_CHANGED:
			SetProjectionMatrix(camera.GetWidth(), camera.GetHeight());
            break;
		case LIGHT_POSITION_CHANGED:
			m_lightPosition = m_light->GetPosition();
    }
}
