#pragma once

#include <vector>
#include <cstdint>

#include "Shader.hpp"
#include "Render/VertexBuffer.hpp"
#include "Transformation.hpp"
#include "Texture.hpp"
#include "IResource.hpp"
#include "Render/Vertex.hpp"

class DrawableObject
{
public:
	DrawableObject();

	DrawableObject(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<Shader>& shader, const std::shared_ptr<Texture>& texture);
	
	virtual ~DrawableObject() = default;

	void Activate();

	[[nodiscard]] uint32_t GetVertexCount() const;

	Transformation& GetTransformation();

	[[nodiscard]] std::weak_ptr<Shader> GetShader();

	[[nodiscard]] const std::weak_ptr<Shader> GetCShader() const;

	[[nodiscard]] std::weak_ptr<Texture> GetTexture();

	[[nodiscard]] const std::weak_ptr<Texture> GetCTexture() const;

	void SetShader(const std::shared_ptr<Shader>& shader);

	void SetTexture(const std::shared_ptr<Texture>& texture);

private:
	Transformation m_transformation;
	std::shared_ptr<VertexBuffer> m_vertexBuffer;
    std::shared_ptr<Shader> m_shader;
	std::shared_ptr<Texture> m_texture;
};
