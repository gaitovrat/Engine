#pragma once

#include "IComponent.h"

#include <vector>
#include <memory>

class Composite : public IComponent
{
public:
	virtual void Activate();

	virtual void AddComponent(const std::shared_ptr<IComponent>& component);

	const std::vector<std::shared_ptr<IComponent>>& GetComponents() const;

private:
	std::vector<std::shared_ptr<IComponent>> m_components;
};