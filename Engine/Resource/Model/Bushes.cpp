#include "Bushes.h"

#include "Resource/ResourceManager.h"
#include "Raw/bushes.h"

Bushes::Bushes() : Bushes(ResourceManager::GetInstance().GetShader("1"))
{
}

Bushes::Bushes(Shader& shader) : DrawableObject(bushes, sizeof(bushes) / sizeof(bushes[0]), shader)
{
}
