#include "PointLight.hpp"

PointLight::PointLight() : AbstractLight(glm::vec3(0), 1.0f, 0.09f, 0.032f, 
    glm::vec3(0.2f, 0.2f, 0.2f), glm::vec3(0.5f, 0.5f, 0.5f), glm::vec3(1.0f, 1.0f, 1.0f))
{
}

ELightType PointLight::Type() const
{
    return POINT;
}
