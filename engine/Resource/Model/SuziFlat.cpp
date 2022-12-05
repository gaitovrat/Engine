#include "SuziFlat.hpp"

#include "RawModel/suzi_flat.h"
#include "Resource/ResourceManager.hpp"

SuziFlat::SuziFlat() : SuziFlat(ResourceManager::GetInstance().GetShader("constant"))
{
}

SuziFlat::SuziFlat(const std::shared_ptr<Shader>& shader) : DrawableObject(std::make_shared<VertexBuffer>(Vertex::ToVector(suziFlat, sizeof(suziFlat) / sizeof(float), Vertex::NORMAL)), shader)
{
}
