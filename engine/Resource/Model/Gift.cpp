#include "Gift.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/gift.hpp"
#include "Configuration.hpp"

Gift::Gift() : Gift(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

Gift::Gift(Shader& shader) : DrawableObject(gift, sizeof(gift) / sizeof(gift[0]), shader)
{
}
