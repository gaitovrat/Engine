#include "SuziFlat.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/suzi_flat.hpp"
#include "Configuration.hpp"

SuziFlat::SuziFlat() : SuziFlat(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

SuziFlat::SuziFlat(Shader& shader) : DrawableObject(suziFlat, sizeof(suziFlat) / sizeof(suziFlat[0]), shader)
{
}
