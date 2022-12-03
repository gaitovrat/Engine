#include "Renderer.hpp"

#include <GL/glew.h>

#include "Resource/DrawableObject.hpp"

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(DrawableObject& object)
{
	glEnable(GL_DEPTH_TEST);
	object.Activate();
	glDrawElements(GL_TRIANGLES, object.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(SkyBox& skyBox)
{
	glDisable(GL_DEPTH_TEST);
	skyBox.Activate();
	glDrawElements(GL_TRIANGLES, skyBox.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
}
