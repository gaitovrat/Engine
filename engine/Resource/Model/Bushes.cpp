#include "Bushes.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/bushes.hpp"

Bushes::Bushes() : Bushes(ResourceManager::GetInstance().GetShader("1"))
{
}

Bushes::Bushes(Shader& shader) : DrawableObject(bushes, sizeof(bushes) / sizeof(bushes[0]), shader)
{
}
