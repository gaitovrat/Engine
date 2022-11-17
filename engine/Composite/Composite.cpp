#include "Composite.hpp"

void Composite::Activate()
{
	for (auto& component : m_components)
	{
		component->Activate();
	}
}

void Composite::AddComponent(const std::shared_ptr<IComponent>& component)
{
	m_components.push_back(component);
}

const std::vector<std::shared_ptr<IComponent>>& Composite::GetComponents() const
{
	return m_components;
}
