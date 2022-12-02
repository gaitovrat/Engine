#include "Skydome.hpp"

#include "Resource/ResourceManager.hpp"

Skydome::Skydome() :
	DrawableObject("assets/mesh/skydome.obj",
		ResourceManager::GetInstance().GetShader("texture"),
		*ResourceManager::GetInstance().GetTexture("skydome.png"))
{
}
