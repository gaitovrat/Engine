#include "SuziSmooth.hpp"

#include "RawModel/suzi_smooth.h"
#include "Resource/ResourceManager.hpp"

SuziSmooth::SuziSmooth() : SuziSmooth(ResourceManager::GetInstance().GetShader("constant"))
{
}

SuziSmooth::SuziSmooth(const std::shared_ptr<Shader>& shader) : DrawableObject(std::make_shared<VertexBuffer>(Vertex::ToVector(suziSmooth, sizeof(suziSmooth) / sizeof(float), Vertex::NORMAL)), shader)
{
}
