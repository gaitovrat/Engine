#include "VertexBuffer.hpp"

#include <GL/glew.h>

VertexBuffer::VertexBuffer(const float* points, const uint32_t size)
{
	uint32_t vbo(0);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, size * sizeof(points[0]), points, GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	for (int i = 0; i < 2; ++i)
	{
		uint32_t offset = i * sizeof(points[0]) * 3;

		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, 3, GL_FLOAT, GL_FALSE, sizeof(points[0]) * 6, reinterpret_cast<void*>(offset));
	}
}

void VertexBuffer::Bind() const
{
	glBindVertexArray(m_vao);
}
