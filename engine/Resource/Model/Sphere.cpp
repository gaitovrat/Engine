#include "Sphere.hpp"

#include "RawModel/sphere.h"
#include "Resource/ResourceManager.hpp"

Sphere::Sphere() : Sphere(ResourceManager::GetInstance().GetShader("constant"))
{
}

Sphere::Sphere(const std::shared_ptr<Shader>& shader) : DrawableObject(std::make_shared<VertexBuffer>(Vertex::ToVector(sphere, sizeof(sphere) / sizeof(float), Vertex::NORMAL)), shader)
{
}
