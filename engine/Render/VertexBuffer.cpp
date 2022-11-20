#include "VertexBuffer.hpp"

#include <GL/glew.h>

#include <utility>

VertexBuffer::VertexBuffer() : VertexBuffer(std::vector<Vertex>())
{
}

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices) : m_vao(0), m_ibo(0), m_data(std::move(vertices))
{
	Init();
}

void VertexBuffer::Init()
{
	if (m_data.empty())
	{
		return;
	}

	uint32_t vbo(0);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(m_data[0]), &m_data.front(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	constexpr int offsets[] = { 0, (3 * sizeof(float)), (6 * sizeof(float)), (8 * sizeof(float))};
	constexpr int size[] = { 3, 3, 2, 3 };
	for (int i = 0; i < 4; ++i)
	{
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, size[i], GL_FLOAT, GL_FALSE, sizeof(m_data[0]), (void*)(offsets[i]));
	}
}

void VertexBuffer::Bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBindVertexArray(m_vao);
}

void VertexBuffer::SetData(const std::vector<Vertex>& vertices)
{
	m_data = vertices;
	Init();
}

void VertexBuffer::SetIndicies(unsigned* indicies, int size)
{
	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
}
