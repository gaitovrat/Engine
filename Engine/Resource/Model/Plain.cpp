#include "Plain.h"

#include "Raw/plain.h"
#include "Resource/ResourceManager.h"

Plain::Plain() : Plain(ResourceManager::GetInstance().GetShader("1"))
{
}

Plain::Plain(Shader& shader) : DrawableObject(plain, sizeof(plain) / sizeof(plain[0]), shader)
{
}
