#include "Renderer.hpp"

#include <GL/glew.h>

#include "Resource/DrawableObject.hpp"

Renderer::Renderer()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_STENCIL_TEST);
	glStencilOp(GL_KEEP, GL_KEEP, GL_REPLACE);
}

void Renderer::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(DrawableObject& object)
{
	object.Activate();
	glStencilFunc(GL_ALWAYS, object.Id(), 0xFF);
	if (object.HasIndexes())
	{
		glDrawElements(GL_TRIANGLES, object.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
	}
	else
	{
		glDrawArrays(GL_TRIANGLES, 0, object.GetVertexCount());
	}
}

void Renderer::Draw(SkyBox& skyBox)
{
	glDisable(GL_DEPTH_TEST);
	skyBox.Activate();
	glDrawElements(GL_TRIANGLES, skyBox.GetVertexCount(), GL_UNSIGNED_INT, nullptr);
	glClear(GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}
