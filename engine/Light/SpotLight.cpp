#include "SpotLight.hpp"

#include "Camera.hpp"

SpotLight::SpotLight() : SpotLight(Camera::GetInstance().Eye(), Camera::GetInstance().Target())
{
}

SpotLight::SpotLight(glm::vec3 position, glm::vec3 direction) : AbstractLight(position, direction,
    glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(17.5f)),
    1.0f, 0.09f, 0.032f,
    glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.7f, 0.7f, 0.7f), glm::vec3(1.0f, 1.0f, 1.0f))
{
}

ELightType SpotLight::Type() const
{
    return SPOT;
}
