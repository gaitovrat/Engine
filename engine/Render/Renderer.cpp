#include "Renderer.hpp"

#include <GL/glew.h>

#include "Resource/DrawableObject.hpp"
#include "Resource/Shader.hpp"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(DrawableObject& object)
{
	object.Activate();

	glDrawArrays(GL_TRIANGLES, 0, object.GetVertexCount());
}
