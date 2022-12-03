#include "Skydome.hpp"

#include "Resource/ResourceManager.hpp"

Skydome::Skydome() :
	DrawableObject(
		ResourceManager::GetInstance().GetMesh("skydome.obj"),
		ResourceManager::GetInstance().GetShader("texture"),
		ResourceManager::GetInstance().GetTexture("skydome.png"))
{
}
