#include "DrawableObject.hpp"

#include <glm/gtc/matrix_transform.hpp>

#include "ResourceManager.hpp"

DrawableObject::DrawableObject(const std::vector<float>& vertecies, Shader& shader) : DrawableObject(&vertecies.front(), vertecies.size(), shader)
{
}

DrawableObject::DrawableObject(const float* points, const uint32_t size, Shader& shader) : m_vertexBuffer(points, size), m_vertexCount(size / 6), m_shader(&shader)
{
}

void DrawableObject::Activate()
{
    m_shader->Activate();
	m_tranformation.Activate();
    m_shader->SetModelMatrix(m_tranformation.GetMatrix());
    m_shader->UpdateUniforms();
    m_vertexBuffer.Bind();
}

uint32_t DrawableObject::GetVertexCount() const
{
	return m_vertexCount;
}

Transformation& DrawableObject::GetTransformation()
{
	return m_tranformation;
}

Shader& DrawableObject::GetShader()
{
    return *m_shader;
}

void DrawableObject::SetShader(Shader& shader)
{
    m_shader = &shader;
}
