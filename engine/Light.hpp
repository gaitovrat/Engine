#pragma once

#include <glm/glm.hpp>
#include <vector>

#include "Observer/ISubject.hpp"

class Light : public ISubject
{
public:
	Light();

	Light(glm::vec3 position);

	virtual ~Light() = default;

	glm::vec3 GetPosition() const;

	void SetPosition(glm::vec3 position);

	void AddObserver(IObserver* observer) override;

	void NotifyAll(EObserverEvent event) override;

private:
	glm::vec3 m_position;
	std::vector<IObserver*> m_observers;
};
