#include "KeyboardEvent.hpp"

void KeyboardEvent::AddListener(const KeyboardEventListener& listener)
{
	m_listeners.push_back(listener);
}

void KeyboardEvent::Dispath() const
{
	for (const auto& listener : m_listeners)
	{
		listener.Execute();
	}
}

KeyboardEvent& KeyboardEvent::GetInstance()
{
	static KeyboardEvent instance;

	return instance;
}
