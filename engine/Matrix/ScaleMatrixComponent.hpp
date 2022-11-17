#pragma once

#include <glm/glm.hpp>

#include "AbstractMatrixComponent.hpp"

class ScaleMatrixComponent : public AbstractMatrixComponent
{
public:
	ScaleMatrixComponent();

	ScaleMatrixComponent(const glm::vec3 scale);

	void Activate() override;

	glm::vec3 GetScale() const;

	void SetScale(const glm::vec3 scale);

private:
	glm::vec3 m_scale;
};
