#include "Plain.hpp"

#include "Raw/plain.hpp"
#include "Resource/ResourceManager.hpp"

Plain::Plain() : Plain(ResourceManager::GetInstance().GetShader("1"))
{
}

Plain::Plain(Shader& shader) : DrawableObject(plain, sizeof(plain) / sizeof(plain[0]), shader)
{
}
