#include "Plain.hpp"

#include "Resource/ResourceManager.hpp"
#include "RawModel/plain.h"

Plain::Plain() : Plain(ResourceManager::GetInstance().GetShader("constant"))
{
}

Plain::Plain(const std::shared_ptr<Shader>& shader) : DrawableObject(std::make_shared<VertexBuffer>(Vertex::ToVector(plain, sizeof(plain) / sizeof(float), Vertex::NORMAL)), shader)
{
}
