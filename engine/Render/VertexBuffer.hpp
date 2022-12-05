#pragma once

#include <cstdint>
#include <vector>
#include <string>
#include <optional>
#include "Vertex.hpp"
#include "Resource/IResource.hpp"

class VertexBuffer : public IResource
{
public:
	VertexBuffer();

	VertexBuffer(const std::string& filepath);

	explicit VertexBuffer(std::vector<Vertex> vertices);

	void Bind() const;

	void Load(const std::string& filepath) override;

	bool HasIndexes() const;

	_NODISCARD uint32_t VertexCount() const;

private:
	void Init();

	void SetData(const std::vector<Vertex>& vertices);
	
	void SetIndicies(unsigned* indicies, int size);

	uint32_t m_vao;
	uint32_t m_ibo;
	bool m_hasIndexes;
	std::vector<Vertex> m_data;
	uint32_t m_vertexCount;
};

