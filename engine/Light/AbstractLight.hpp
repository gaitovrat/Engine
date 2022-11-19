#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "Observer/ISubject.hpp"
#include "ELightType.hpp"

class AbstractLight : public ISubject
{
public:
	AbstractLight();

	~AbstractLight() override = default;

	AbstractLight(const glm::vec3& position, float constant, float linear, float quadratic, const glm::vec3& ambient,
		const glm::vec3& diffuse, const glm::vec3& specular);

	AbstractLight(const AbstractLight& other) = default;

	AbstractLight(AbstractLight&& other) noexcept;

	AbstractLight& operator=(const AbstractLight& other);

	AbstractLight& operator=(AbstractLight&& other) noexcept;

	[[nodiscard]] glm::vec3 Position() const;

	void SetPosition(glm::vec3 position);

	[[nodiscard]] float Constant() const;

	void SetConstant(float constant);

	[[nodiscard]] float Linear() const;

	void SetLinear(float linear);

	[[nodiscard]] float Quadratic() const;

	void SetQuadratic(float quadratic);

	[[nodiscard]] glm::vec3 Ambient() const;

	void SetAmbient(glm::vec3 ambient);

	[[nodiscard]] glm::vec3 Diffuse() const;

	void SetDiffuse(glm::vec3 diffuse);

	[[nodiscard]] glm::vec3 Specular() const;

	void SetSpecular(glm::vec3 specular);

	[[nodiscard]] uint64_t Id() const;

	[[nodiscard]] virtual ELightType Type() const = 0;

	void AddObserver(IObserver* observer) override;

	void NotifyAll(EObserverEvent event) override;

private:
	std::vector<IObserver*> m_observers;

	glm::vec3 m_position;

	float m_constant;
	float m_linear;
	float m_quadratic;

	glm::vec3 m_ambient;
	glm::vec3 m_diffuse;
	glm::vec3 m_specular;

	uint64_t m_id;
	static uint64_t m_lastId;
};
