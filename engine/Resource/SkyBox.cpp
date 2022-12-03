#include "SkyBox.hpp"

#include "Resource/ResourceManager.hpp"

#include <memory>

SkyBox::SkyBox() :
	DrawableObject(ResourceManager::GetInstance().GetMesh("box.obj"),
		ResourceManager::GetInstance().GetShader("skybox"), 
		std::make_shared<Texture>(
			"assets/texture/skybox/posx.jpg",
			"assets/texture/skybox/posy.jpg",
			"assets/texture/skybox/posz.jpg",
			"assets/texture/skybox/negx.jpg",
			"assets/texture/skybox/negy.jpg",
			"assets/texture/skybox/negz.jpg"
		))
{
}
