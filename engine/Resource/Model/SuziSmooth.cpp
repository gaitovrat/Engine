#include "SuziSmooth.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/suzi_smooth.hpp"
#include "Configuration.hpp"

SuziSmooth::SuziSmooth() : SuziSmooth(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

SuziSmooth::SuziSmooth(Shader& shader) : DrawableObject(suziSmooth, sizeof(suziSmooth) / sizeof(suziSmooth[0]), shader)
{
}
