#include "Gift.h"

#include "Resource/ResourceManager.h"
#include "Raw/gift.h"

Gift::Gift() : Gift(ResourceManager::GetInstance().GetShader("1"))
{
}

Gift::Gift(Shader& shader) : DrawableObject(gift, sizeof(gift) / sizeof(gift[0]), shader)
{
}
