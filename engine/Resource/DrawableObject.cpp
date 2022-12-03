#include "DrawableObject.hpp"

#include "ResourceManager.hpp"
#include "Configuration.hpp"

DrawableObject::DrawableObject() : DrawableObject(
    ResourceManager::GetInstance().GetMesh(Configuration::DefaultMesh),
    ResourceManager::GetInstance().GetShader(Configuration::DefaultShader), 
    ResourceManager::GetInstance().GetTexture(Configuration::DefaultTexture))
{
}

DrawableObject::DrawableObject(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<Shader>& shader, const std::shared_ptr<Texture>& texture) :
	m_vertexBuffer(vertexBuffer), m_shader(shader), m_texture(texture)
{
}

void DrawableObject::Activate()
{
    m_shader->Activate();
    m_shader->SetModelMatrix(m_transformation.GetMatrix());
	m_transformation.Activate();
    m_shader->UpdateUniforms();
    m_vertexBuffer->Bind();
    m_texture->Bind();
}

uint32_t DrawableObject::GetVertexCount() const
{
	return m_vertexBuffer->VertexCount();
}

Transformation& DrawableObject::GetTransformation()
{
	return m_transformation;
}

std::weak_ptr<Shader> DrawableObject::GetShader()
{
    return m_shader;
}

const std::weak_ptr<Shader> DrawableObject::GetCShader() const
{
    return m_shader;
}

std::weak_ptr<Texture> DrawableObject::GetTexture()
{
    return m_texture;
}

const std::weak_ptr<Texture> DrawableObject::GetCTexture() const
{
    return m_texture;
}

void DrawableObject::SetShader(const std::shared_ptr<Shader>& shader)
{
    m_shader = shader;
}

void DrawableObject::SetTexture(const std::shared_ptr<Texture>& texture)
{
    m_texture = texture;
}
