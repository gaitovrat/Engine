#include "KeyboardEventListener.h"

KeyboardEventListener::KeyboardEventListener(Window& context, EKey source, std::function<void()> action) : m_context(context), m_source(source), m_action(action)
{
}

void KeyboardEventListener::Execute() const
{
	if (m_context.IsPressed(m_source))
	{
		m_action();
	}
}
