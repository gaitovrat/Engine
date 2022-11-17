#include "ScaleMatrixComponent.h"

#include <glm/gtx/transform.hpp>

ScaleMatrixComponent::ScaleMatrixComponent() : ScaleMatrixComponent(glm::vec3(0))
{
}

ScaleMatrixComponent::ScaleMatrixComponent(const glm::vec3 scale) : AbstractMatrixComponent(), m_scale(scale)
{
}

void ScaleMatrixComponent::Activate()
{
	glm::mat4 scaleMatrix = glm::scale(GetMatrix(), m_scale);
	SetMatrix(scaleMatrix);
}

glm::vec3 ScaleMatrixComponent::GetScale() const
{
	return m_scale;
}

void ScaleMatrixComponent::SetScale(const glm::vec3 scale)
{
	m_scale = scale;
}
