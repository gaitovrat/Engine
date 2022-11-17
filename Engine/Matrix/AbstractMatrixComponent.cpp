#include "AbstractMatrixComponent.h"

AbstractMatrixComponent::AbstractMatrixComponent() : AbstractMatrixComponent(glm::mat4(1))
{
}

AbstractMatrixComponent::AbstractMatrixComponent(const glm::mat4 matrix) : m_matrix(matrix)
{
}

void AbstractMatrixComponent::SetMatrix(const glm::mat4 matrix)
{
	m_matrix = matrix;
}

glm::mat4 AbstractMatrixComponent::GetMatrix() const
{
	return m_matrix;
}
