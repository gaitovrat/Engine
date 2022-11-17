#pragma once

#include <cstdint>
#include <vector>
#include <initializer_list>

class VertexBuffer
{
public:
	VertexBuffer(const float* points, uint32_t size);

	void Bind() const;

private:
	uint32_t m_vao;
};

