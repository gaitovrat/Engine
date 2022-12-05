#pragma once

#include <vector>
#include <cstdint>
#include <optional>

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

	DrawableObject(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<Shader>& shader, const std::optional<std::shared_ptr<Texture>>& texture);

	DrawableObject(const std::shared_ptr<VertexBuffer>& vertexBuffer, const std::shared_ptr<Shader>& shader);
	
	virtual ~DrawableObject() = default;

	void Activate();

	_NODISCARD uint32_t GetVertexCount() const;

	Transformation& GetTransformation();

	_NODISCARD std::weak_ptr<Shader> GetShader();

	_NODISCARD const std::weak_ptr<Shader> GetCShader() const;

	_NODISCARD std::optional<std::weak_ptr<Texture>> GetTexture();

	_NODISCARD const std::optional<std::weak_ptr<Texture>> GetCTexture() const;

	_NODISCARD bool HasIndexes() const;

	_NODISCARD uint32_t Id() const;

	void SetShader(const std::shared_ptr<Shader>& shader);

	void SetTexture(const std::shared_ptr<Texture>& texture);

private:
	uint32_t m_id;
	static uint32_t s_id;
	Transformation m_transformation;
	std::shared_ptr<VertexBuffer> m_vertexBuffer;
    std::shared_ptr<Shader> m_shader;
	std::optional<std::shared_ptr<Texture>> m_texture;
};
