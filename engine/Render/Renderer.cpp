#include "Renderer.hpp"

#include <GL/glew.h>

#include "Resource/DrawableObject.hpp"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
}

void Renderer::Clear()
{
	glClearColor(0.39f, 0.76f, 0.96f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(DrawableObject& object)
{
	object.Activate();
	glDrawElements(GL_TRIANGLES, object.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
}

void Renderer::Draw(SkyBox& skyBox)
{
	glDepthFunc(GL_LEQUAL);
	skyBox.Activate();
	glDrawElements(GL_TRIANGLES, skyBox.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
	glDepthFunc(GL_LESS);
}
