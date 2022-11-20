#pragma once

#include <cstdint>
#include <vector>
#include "Vertex.hpp"

class VertexBuffer
{
public:
	VertexBuffer();

	explicit VertexBuffer(std::vector<Vertex> vertices);

	void Init();

	void Bind() const;

	void SetData(const std::vector<Vertex>& vertices);

	void SetIndicies(unsigned* indicies, int size);

private:
	uint32_t m_vao;
	uint32_t m_ibo;
	std::vector<Vertex> m_data;
};

