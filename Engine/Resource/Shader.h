#pragma once

#include <cstdint>
#include <vector>
#include <glm/glm.hpp>

#include "Render/Shader/VertexShader.h"
#include "Render/Shader/FragmentShader.h"
#include "Observer/IObserver.h"
#include "Light.h"

class Camera;

class Shader final : public IObserver
{
private:
	Shader();

public:
	Shader(const VertexShader& vertexShader, const FragmentShader& fragmentShader);

	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);

	Shader(const VertexShader& vertexShader, const FragmentShader& fragmentShader, Light& light);

	void Link();

	void Activate() const;

	void SetModelMatrix(const glm::mat4 modelMatrix);

	void SetLight(Light& light);

	void UpdateUniforms() const;

	void Notify(EObserverEvent event) override;

private:
	void SetProjectionMatrix(int width, int height);

private:
	uint32_t m_id;
	uint32_t m_modelId;
	glm::mat4 m_modelMatrix;
	uint32_t m_projectionId;
	glm::mat4 m_projectionMatrix;
	uint32_t m_viewId;
	glm::mat4 m_viewMatrix;
	std::vector<BaseShader> m_shaders;
	uint32_t m_eyeId;
	glm::vec3 m_lightPosition;
	uint32_t m_lightId;
	Light* m_light;
};
