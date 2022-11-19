#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight() : DirectionalLight(glm::vec3(-0.2f, -1.0f, -0.3f))
{
}

DirectionalLight::DirectionalLight(glm::vec3 direction) : AbstractLight(glm::vec3(0), direction, 0, 0, 
    1.0f, 0.09f, 0.032f,
    glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f))
{
}

ELightType DirectionalLight::Type() const
{
    return DIRECTIONAL;
}
