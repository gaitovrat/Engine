#include "Sphere.hpp"

#include "Raw/sphere.hpp"
#include "Resource/ResourceManager.hpp"

Sphere::Sphere() : Sphere(ResourceManager::GetInstance().GetShader("1"))
{
}

Sphere::Sphere(Shader& shader) : DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), shader)
{
}
