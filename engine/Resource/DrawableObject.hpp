#pragma once

#include <vector>
#include <cstdint>

#include "Shader.hpp"
#include "Render/VertexBuffer.hpp"
#include "Transformation.hpp"
#include "Texture.hpp"
#include "IResource.hpp"
#include "Render/Vertex.hpp"

class DrawableObject : public IResource
{
	DrawableObject(Shader& shader, Texture& texture);

public:
	DrawableObject(const std::vector<Vertex>& vertecies, Shader& shader, Texture& texture);

	DrawableObject(std::string filepath, Shader& shader, Texture& texture);
	
	virtual ~DrawableObject() = default;

	void Activate();

	[[nodiscard]] uint32_t GetVertexCount() const;

	Transformation& GetTransformation();

	[[nodiscard]] Shader& GetShader() const;

	[[nodiscard]] Texture& GetTexture() const;

	void SetShader(Shader& shader);

	void SetTexture(Texture& texture);

	void Load(std::string filepath) override;

private:
	uint32_t m_vertexCount;
	VertexBuffer m_vertexBuffer;
	Transformation m_transformation;
    Shader* m_shader;
	Texture* m_texture;
};
