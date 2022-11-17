#include "SuziSmooth.h"

#include "Resource/ResourceManager.h"
#include "Raw/suzi_smooth.h"

SuziSmooth::SuziSmooth() : SuziSmooth(ResourceManager::GetInstance().GetShader("1"))
{
}

SuziSmooth::SuziSmooth(Shader& shader) : DrawableObject(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), shader)
{
}
