#pragma once

#include <cstdint>
#include <vector>
#include <glm/glm.hpp>

#include "Render/Shader/VertexShader.hpp"
#include "Render/Shader/FragmentShader.hpp"
#include "Observer/IObserver.hpp"
#include "Light/AbstractLight.hpp"
#include "IResource.hpp"

class Camera;

class Shader final : public IObserver, public IResource
{
public:
	Shader();

	Shader(const VertexShader& vertexShader, const FragmentShader& fragmentShader);

	Shader(const char* vertexShaderSource, const char* fragmentShaderSource);

	explicit Shader(std::string filepath);

	void Link();

	void Activate() const;

	void SetModelMatrix(const glm::mat4 modelMatrix);

	void SetLights(const std::vector<std::shared_ptr<AbstractLight>>& lights);

	void SetLights(const std::vector<std::weak_ptr<AbstractLight>>& lights);

	void UpdateLights(const std::vector<std::weak_ptr<AbstractLight>>& lights) const;

	void UpdateLight(const std::weak_ptr<AbstractLight>& light, uint64_t index) const;

	void UpdateLight(AbstractLight* light, uint64_t index) const;

	void UpdateUniforms() const;

	void Notify(EObserverEvent event, ISubject* source) override;

	void Load(const std::string& filepath) override;

private:
	void SetProjectionMatrix(int width, int height);

	void Init(const char* vertexShaderSource, const char* fragmentShaderSource);

	int32_t m_id;
	int32_t m_modelId;
	glm::mat4 m_modelMatrix;
	int32_t m_projectionId;
	glm::mat4 m_projectionMatrix;
	int32_t m_viewId;
	glm::mat4 m_viewMatrix;
	std::vector<BaseShader> m_shaders;
	int32_t m_eyeId;
	int32_t m_textureId;

	std::vector<std::weak_ptr<AbstractLight>> m_lights;
};
