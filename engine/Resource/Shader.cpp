#include "Resource/Shader.hpp"

#include <GL/glew.h>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>
#include <glm/gtx/string_cast.hpp>
#include <memory>

#include "Exception/GLException.hpp"

#include "Camera.hpp"

Shader::Shader() : m_id(0), m_modelId(0), m_modelMatrix(1.f), m_projectionId(0), m_projectionMatrix(1.f), m_viewId(0), m_viewMatrix(1.f),
                   m_eyeId(0), m_textureId(-1)
{
	m_id = glCreateProgram();

	auto& camera = Camera::GetInstance();
    camera.AddObserver(this);
	m_viewMatrix = camera.ToMatrix();
	SetProjectionMatrix(camera.Width(), camera.Height());
}

Shader::Shader(const VertexShader& vertexShader, const FragmentShader& fragmentShader) : Shader()
{
	m_shaders.push_back(vertexShader);
	m_shaders.push_back(fragmentShader);
}

Shader::Shader(const char* vertexShaderSource, const char* fragmentShaderSource) : Shader()
{
	Init(vertexShaderSource, fragmentShaderSource);
}

Shader::Shader(const std::string filepath) : Shader()
{
	Load(filepath);
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
	m_textureId = glGetUniformLocation(m_id, "textureID");
}

void Shader::Activate() const
{
	glUseProgram(m_id);
}	

void Shader::SetModelMatrix(const glm::mat4 modelMatrix)
{
	m_modelMatrix = modelMatrix;
}

void Shader::SetLights(const std::vector<std::weak_ptr<AbstractLight>>& lights)
{
	m_lights = lights;
}

void Shader::SetLights(const std::vector<std::shared_ptr<AbstractLight>>& lights)
{
	m_lights.clear();
	for (const auto& light : lights)
	{
		m_lights.push_back(light);
	}
}

void Shader::SetProjectionMatrix(const int width, const int height)
{
	m_projectionMatrix = glm::perspective(glm::radians(45.0f), float(width) / float(height), 0.1f, 100.0f);
}

void Shader::Init(const char* vertexShaderSource, const char* fragmentShaderSource)
{
	m_shaders.emplace_back(vertexShaderSource, VERTEX);
	m_shaders.emplace_back(fragmentShaderSource, FRAGMENT);
}

void Shader::UpdateLights(const std::vector<std::weak_ptr<AbstractLight>>& lights) const
{
	for (const auto& light : lights)
	{
		if (auto lightLock = light.lock())
		{
			UpdateLight(lightLock, lightLock->Id());
		}
	}
}

void Shader::UpdateLight(const std::weak_ptr<AbstractLight>& light, const uint64_t index) const
{
	if (auto lightLock = light.lock())
	{
		UpdateLight(lightLock.get(), index);
	}
}

void Shader::UpdateLight(AbstractLight* light, uint64_t index) const
{
	const auto position = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].position").c_str());
	const auto direction = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].direction").c_str());
	const auto cutOff = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].cutOff").c_str());
	const auto outerCutOff = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].outerCutOff").c_str());
	const auto ambient = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].ambient").c_str());
	const auto diffuse = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].diffuse").c_str());
	const auto specular = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].specular").c_str());
	const auto constant = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].constant").c_str());
	const auto linear = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].linear").c_str());
	const auto quadratic = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].quadratic").c_str());
	const auto type = glGetUniformLocation(m_id, ("lights[" + std::to_string(index) + "].lightType").c_str());
	const auto lightsSize = glGetUniformLocation(m_id, "lightsSize");

	glUniform3f(position, light->Position().x, light->Position().y, light->Position().z);
	glUniform3f(direction, light->Direction().x, light->Direction().y, light->Direction().z);
	glUniform1f(cutOff, light->CutOff());
	glUniform1f(outerCutOff, light->OuterCutOff());
	glUniform3f(ambient, light->Ambient().x * 0.1f, light->Ambient().y * 0.1f, light->Ambient().z * 0.1f);
	glUniform3f(diffuse, light->Diffuse().x, light->Diffuse().y, light->Diffuse().z);
	glUniform3f(specular, light->Specular().x, light->Specular().y, light->Specular().z);
	glUniform1f(constant, light->Constant());
	glUniform1f(linear, light->Linear());
	glUniform1f(quadratic, light->Quadratic());
	glUniform1i(type, light->Type());
	glUniform1i(lightsSize, m_lights.size());
}

void Shader::UpdateUniforms() const
{
	glUniformMatrix4fv(m_viewId, 1, GL_FALSE, value_ptr(m_viewMatrix));
	glUniformMatrix4fv(m_projectionId, 1, GL_FALSE, value_ptr(m_projectionMatrix));
	glUniformMatrix4fv(m_modelId, 1, GL_FALSE, value_ptr(m_modelMatrix));
	glUniform3fv(m_eyeId, 1, value_ptr(Camera::GetInstance().Eye()));
	glUniform1i(m_textureId, 0);

	UpdateLights(m_lights);
}

void Shader::Notify(const EObserverEvent event, ISubject* source)
{
	const auto& camera = Camera::GetInstance();

    switch (event)
    {
        case VIEW_MATRIX_CHANGED:
            m_viewMatrix = camera.ToMatrix();
			for (const auto& light : m_lights)
			{
				if (auto lightLock = light.lock())
				{
					if (lightLock->Type() == SPOT)
					{
						lightLock->SetPosition(camera.Eye());
						lightLock->SetDirection(camera.Target());
					}
				}
			}
            break;
        case PROJECTION_MATRIX_CHANGED:
			SetProjectionMatrix(camera.Width(), camera.Height());
            break;
		case LIGHT_POSITION_CHANGED:
			if (source != nullptr)
			{
				const auto light = dynamic_cast<AbstractLight*>(source);
				UpdateLight(light, light->Id());
			}
			break;
    }
}

void Shader::Load(const std::string& filepath)
{
	const std::string vertex = filepath + ".vert";
	const std::string fragment = filepath + ".frag";
	const char* cVertex = vertex.c_str();
	const char* cFragment = fragment.c_str();

	Init(cVertex, cFragment);
}
