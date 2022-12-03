#include "AbstractLight.hpp"

#include "Observer/IObserver.hpp"

uint64_t AbstractLight::m_lastId = 0;

AbstractLight::AbstractLight(const glm::vec3& position, const glm::vec3& direction, float cutOff, float outerCutOff, const float constant, const float linear, const float quadratic, const glm::vec3& ambient,
	const glm::vec3& diffuse, const glm::vec3& specular): m_position(position),
                                                          m_direction(direction),
                                                          m_cutOff(cutOff),
                                                          m_outerCutOff(outerCutOff),
	                                                      m_constant(constant),
	                                                      m_linear(linear),
	                                                      m_quadratic(quadratic),
	                                                      m_ambient(ambient),
	                                                      m_diffuse(diffuse),
	                                                      m_specular(specular),
	                                                      m_id(m_lastId++)
{
}

glm::vec3 AbstractLight::Position() const
{
	return m_position;
}

void AbstractLight::SetPosition(const glm::vec3 position)
{
	m_position = position;
}

float AbstractLight::Constant() const
{
	return m_constant;
}

void AbstractLight::SetConstant(const float constant)
{
	m_constant = constant;
}

float AbstractLight::Linear() const
{
	return m_linear;
}

void AbstractLight::SetLinear(const float linear)
{
	m_linear = linear;
}

float AbstractLight::Quadratic() const
{
	return m_quadratic;
}

void AbstractLight::SetQuadratic(const float quadratic)
{
	m_quadratic = quadratic;
}

glm::vec3 AbstractLight::Ambient() const
{
	return m_ambient;
}

void AbstractLight::SetAmbient(const glm::vec3 ambient)
{
	m_ambient = ambient;
}

glm::vec3 AbstractLight::Diffuse() const
{
	return m_diffuse;
}

void AbstractLight::SetDiffuse(const glm::vec3 diffuse)
{
	m_diffuse = diffuse;
}

glm::vec3 AbstractLight::Specular() const
{
	return m_specular;
}

void AbstractLight::SetSpecular(const glm::vec3 specular)
{
	m_specular = specular;
}

uint64_t AbstractLight::Id() const
{
    return m_id;
}

void AbstractLight::AddObserver(IObserver* observer)
{
    for (const auto& element : m_observers)
    {
        if (element == observer)
        {
            return;
        }
    }

    m_observers.push_back(observer);
}

void AbstractLight::NotifyAll(const EObserverEvent event)
{
    for (const auto& element : m_observers)
    {
		if (element != nullptr)
		{
			element->Notify(event, this);
		}
    }
}

glm::vec3 AbstractLight::Direction() const
{
	return m_direction;
}

void AbstractLight::SetDirection(const glm::vec3 direction)
{
	m_direction = direction;
}

float AbstractLight::CutOff() const
{
	return m_cutOff;
}

void AbstractLight::SetCutOff(const float cutOff)
{
	m_cutOff = cutOff;
}

float AbstractLight::OuterCutOff() const
{
	return m_outerCutOff;
}

void AbstractLight::SetOuterCutOff(const float outerCutOff)
{
	m_outerCutOff = outerCutOff;
}
