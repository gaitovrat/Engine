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
	DrawableObject(const std::shared_ptr<Shader> shader, const Texture& texture);

public:
	DrawableObject();

	DrawableObject(const std::vector<Vertex>& vertecies, const std::shared_ptr<Shader> shader, const Texture& texture);

	DrawableObject(const std::string& filepath, const std::shared_ptr<Shader> shader, const Texture& texture);
	
	virtual ~DrawableObject() = default;

	void Activate();

	[[nodiscard]] uint32_t GetVertexCount() const;

	Transformation& GetTransformation();

	[[nodiscard]] std::shared_ptr<Shader> GetShader();

	[[nodiscard]] const std::shared_ptr<Shader> GetCShader() const;

	[[nodiscard]] Texture& GetTexture();

	[[nodiscard]] const Texture& GetCTexture() const;

	void SetShader(const std::shared_ptr<Shader> shader);

	void SetTexture(const Texture& texture);

	void Load(const std::string& filepath) override;

private:
	uint32_t m_vertexCount;
	VertexBuffer m_vertexBuffer;
	Transformation m_transformation;
    std::shared_ptr<Shader> m_shader;
	Texture m_texture;
};
