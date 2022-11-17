#include "RotateMatrixComponent.hpp"

#include <glm/gtx/transform.hpp>

RotateMatrixComponent::RotateMatrixComponent() : RotateMatrixComponent(.0f, glm::vec3(0))
{
}

RotateMatrixComponent::RotateMatrixComponent(const float angle, const glm::vec3 axis) : AbstractMatrixComponent(), m_angle(angle), m_axis(axis)
{
}

void RotateMatrixComponent::Activate()
{
	glm::mat4 rotateMatrix = glm::rotate(GetMatrix(), m_angle, m_axis);
	SetMatrix(rotateMatrix);
}

float RotateMatrixComponent::GetAngle() const
{
	return m_angle;
}

void RotateMatrixComponent::SetAngle(float angle)
{
	m_angle = angle;
}

glm::vec3 RotateMatrixComponent::GetAxis() const
{
	return m_axis;
}

void RotateMatrixComponent::SetAxis(const glm::vec3 axis)
{
	m_axis = axis;
}
