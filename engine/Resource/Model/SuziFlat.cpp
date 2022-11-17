#include "SuziFlat.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/suzi_flat.hpp"

SuziFlat::SuziFlat() : SuziFlat(ResourceManager::GetInstance().GetShader("1"))
{
}

SuziFlat::SuziFlat(Shader& shader) : DrawableObject(suziFlat, sizeof(suziFlat) / sizeof(suziFlat[0]), shader)
{
}
