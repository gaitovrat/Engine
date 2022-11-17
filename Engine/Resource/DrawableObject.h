#pragma once

#include <vector>
#include <cstdint>

#include "Resource/Shader.h"
#include "Render/VertexBuffer.h"
#include "Transformation.h"

class DrawableObject
{
public:
	DrawableObject(const std::vector<float>& vertecies, Shader& shader);

	DrawableObject(const float* points, uint32_t size, Shader& shader);
	
	virtual ~DrawableObject() = default;

	void Activate();

	uint32_t GetVertexCount() const;

	Transformation& GetTransformation();

	Shader& GetShader();

	void SetShader(Shader& shader);

private:
	uint32_t m_vertexCount;
	VertexBuffer m_vertexBuffer;
	Transformation m_tranformation;
    Shader* m_shader;
};
