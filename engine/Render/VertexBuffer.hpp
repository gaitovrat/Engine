#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include "Vertex.hpp"
#include "Resource/IResource.hpp"

class VertexBuffer : public IResource
{
public:
	VertexBuffer();

	VertexBuffer(const std::string& filepath);

	explicit VertexBuffer(std::vector<Vertex> vertices);

	void Init();

	void Bind() const;

	void SetData(const std::vector<Vertex>& vertices);

	void SetIndicies(unsigned* indicies, int size);

	void Load(const std::string& filepath) override;

	_NODISCARD uint32_t VertexCount() const;

private:
	uint32_t m_vao;
	uint32_t m_ibo;
	std::vector<Vertex> m_data;
	uint32_t m_vertexCount;
};

