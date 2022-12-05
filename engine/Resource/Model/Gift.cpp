#include "Gift.hpp"

#include "Resource/ResourceManager.hpp"
#include "RawModel/gift.h"

Gift::Gift() : Gift(ResourceManager::GetInstance().GetShader("constant"))
{
}

Gift::Gift(const std::shared_ptr<Shader>& shader) :
	DrawableObject(std::make_shared<VertexBuffer>(Vertex::ToVector(gift, sizeof(gift) / sizeof(float), Vertex::NORMAL)), shader)
{
}
