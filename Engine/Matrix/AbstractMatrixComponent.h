#pragma once

#include <glm/glm.hpp>

#include "Composite/IComponent.h"

class AbstractMatrixComponent : public IComponent
{
public:
	AbstractMatrixComponent();

	AbstractMatrixComponent(const glm::mat4 matrix);

	virtual ~AbstractMatrixComponent() = default;

	virtual void SetMatrix(const glm::mat4 matrix);

	virtual glm::mat4 GetMatrix() const;

private:
	glm::mat4 m_matrix;
};
