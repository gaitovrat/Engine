#pragma once

#include <glm/glm.hpp>

#include "Composite/Composite.h"

class Transformation final : public Composite
{
public:
	Transformation();

	Transformation& AddRotate(float angle, glm::vec3 axis);

	Transformation& AddScale(glm::vec3 scale);

	Transformation& AddTranslate(glm::vec3 translate);

	void Activate() override;

	glm::mat4 GetMatrix() const;

private:
	glm::mat4 m_matrix;
};
