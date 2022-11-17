#include "Transformation.hpp"

#include "glm/gtx/transform.hpp"
#include "Matrix/RotateMatrixComponent.hpp"
#include "Matrix/TranslateMatrixComponent.hpp"
#include "Matrix/ScaleMatrixComponent.hpp"
#include "Matrix/AbstractMatrixComponent.hpp"

Transformation::Transformation() : m_matrix(1.f)
{
}

Transformation& Transformation::AddRotate(float angle, glm::vec3 axis)
{
	auto component = static_cast<std::shared_ptr<IComponent>>(std::make_shared<RotateMatrixComponent>(angle, axis));
	AddComponent(component);

	return *this;
}

Transformation& Transformation::AddScale(glm::vec3 scale)
{
	auto component = static_cast<std::shared_ptr<IComponent>>(std::make_shared<ScaleMatrixComponent>(scale));
	AddComponent(component);

	return *this;
}

Transformation& Transformation::AddTranslate(glm::vec3 translate)
{
	auto component = static_cast<std::shared_ptr<IComponent>>(std::make_shared<TranslateMatrixComponent>(translate));
	AddComponent(component);

	return *this;
}

void Transformation::Activate()
{
	glm::mat4 lastMatrix = glm::mat4(1);

	for (auto& component : GetComponents())
	{
		auto* matrixComponent = reinterpret_cast<AbstractMatrixComponent*>(component.get());
		
		matrixComponent->SetMatrix(lastMatrix);
		matrixComponent->Activate();
		lastMatrix = matrixComponent->GetMatrix();
	}

	m_matrix = lastMatrix;
}

glm::mat4 Transformation::GetMatrix() const
{
	return m_matrix;
}
