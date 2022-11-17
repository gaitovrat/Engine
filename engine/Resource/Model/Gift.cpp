#include "Gift.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/gift.hpp"

Gift::Gift() : Gift(ResourceManager::GetInstance().GetShader("1"))
{
}

Gift::Gift(Shader& shader) : DrawableObject(gift, sizeof(gift) / sizeof(gift[0]), shader)
{
}
