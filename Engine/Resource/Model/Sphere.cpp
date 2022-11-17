#include "Sphere.h"

#include "Raw/sphere.h"
#include "Resource/ResourceManager.h"

Sphere::Sphere() : Sphere(ResourceManager::GetInstance().GetShader("1"))
{
}

Sphere::Sphere(Shader& shader) : DrawableObject(sphere, sizeof(sphere) / sizeof(sphere[0]), shader)
{
}
