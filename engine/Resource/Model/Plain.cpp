#include "Plain.hpp"

#include "Raw/plain.hpp"
#include "Resource/ResourceManager.hpp"
#include "Configuration.hpp"

Plain::Plain() : Plain(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

Plain::Plain(Shader& shader) : DrawableObject(plain, sizeof(plain) / sizeof(plain[0]), shader)
{
}
