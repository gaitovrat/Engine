#pragma once

#include <glm/glm.hpp>

#include "AbstractMatrixComponent.h"

class TranslateMatrixComponent : public AbstractMatrixComponent
{
public:
	TranslateMatrixComponent();

	TranslateMatrixComponent(const glm::vec3 translate);

	void Activate() override;

	glm::vec3 GetTranslate() const;

	void SetTranslate(const glm::vec3 tranlate);

private:
	glm::vec3 m_translate;
};
