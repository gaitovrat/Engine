#include "SkyBox.hpp"

#include "Resource/ResourceManager.hpp"

SkyBox::SkyBox() :
	DrawableObject("assets/mesh/skybox.obj", 
		ResourceManager::GetInstance().GetShader("skybox"), 
		Texture(
			"assets/texture/skybox/posx.jpg",
			"assets/texture/skybox/posy.jpg",
			"assets/texture/skybox/posz.jpg",
			"assets/texture/skybox/negx.jpg",
			"assets/texture/skybox/negy.jpg",
			"assets/texture/skybox/negz.jpg"
		))
{
}
