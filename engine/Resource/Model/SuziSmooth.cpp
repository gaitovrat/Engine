#include "SuziSmooth.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/suzi_smooth.hpp"

SuziSmooth::SuziSmooth() : SuziSmooth(ResourceManager::GetInstance().GetShader("1"))
{
}

SuziSmooth::SuziSmooth(Shader& shader) : DrawableObject(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), shader)
{
}
