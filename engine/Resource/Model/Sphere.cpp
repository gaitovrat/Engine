#include "Sphere.hpp"

#include "Raw/sphere.hpp"
#include "Resource/ResourceManager.hpp"
#include "Configuration.hpp"

Sphere::Sphere() : Sphere(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

Sphere::Sphere(Shader& shader) : DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), shader)
{
}
