#include "Light.hpp"

Light::Light() : Light(glm::vec3(.0f, .0f, .0f))
{
}

Light::Light(glm::vec3 position) : m_position(position)
{
}

glm::vec3 Light::GetPosition() const
{
    return m_position;
}

void Light::SetPosition(glm::vec3 position)
{
    m_position = position;

    NotifyAll(LIGHT_POSITION_CHANGED);
}

void Light::AddObserver(IObserver* observer)
{
    for (auto& _observer : m_observers)
    {
        if (_observer == observer)
        {
            return;
        }
    }

    m_observers.push_back(observer);
}

void Light::NotifyAll(EObserverEvent event)
{
    for (auto& observer : m_observers)
    {
        observer->Notify(event);
    }
}
