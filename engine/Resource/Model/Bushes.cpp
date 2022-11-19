#include "Bushes.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/bushes.hpp"
#include "Configuration.hpp"

Bushes::Bushes() : Bushes(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

Bushes::Bushes(Shader& shader) : DrawableObject(bushes, sizeof(bushes) / sizeof(bushes[0]), shader)
{
}
