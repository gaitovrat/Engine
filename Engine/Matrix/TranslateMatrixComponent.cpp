#include "TranslateMatrixComponent.h"

#include <glm/gtx/transform.hpp>

TranslateMatrixComponent::TranslateMatrixComponent() : TranslateMatrixComponent(glm::vec3(0))
{
}

TranslateMatrixComponent::TranslateMatrixComponent(const glm::vec3 translate) : AbstractMatrixComponent(), m_translate(translate)
{
}

void TranslateMatrixComponent::Activate()
{
	glm::mat4 translateMatrix = glm::translate(GetMatrix(), m_translate);
	SetMatrix(translateMatrix);
}

glm::vec3 TranslateMatrixComponent::GetTranslate() const
{
	return m_translate;
}

void TranslateMatrixComponent::SetTranslate(const glm::vec3 tranlate)
{
	m_translate = tranlate;
}
