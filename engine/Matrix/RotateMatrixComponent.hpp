#pragma once

#include <glm/glm.hpp>

#include "AbstractMatrixComponent.hpp"

class RotateMatrixComponent final : public AbstractMatrixComponent
{
public:
	RotateMatrixComponent();

	RotateMatrixComponent(float angle, const glm::vec3 axis);

	void Activate() override;

	float GetAngle() const;

	void SetAngle(float angle);

	glm::vec3 GetAxis() const;

	void SetAxis(const glm::vec3 axis);

private:
	float m_angle;
	glm::vec3 m_axis;
};
