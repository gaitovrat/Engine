#include "SuziFlat.h"

#include "Resource/ResourceManager.h"
#include "Raw/suzi_flat.h"

SuziFlat::SuziFlat() : SuziFlat(ResourceManager::GetInstance().GetShader("1"))
{
}

SuziFlat::SuziFlat(Shader& shader) : DrawableObject(suziFlat, sizeof(suziFlat) / sizeof(suziFlat[0]), shader)
{
}
