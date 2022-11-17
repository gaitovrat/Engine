#pragma once

#include <functional>

#include "Window.h"
#include "EKey.h"

class KeyboardEventListener final
{
public:
	KeyboardEventListener(Window& context, EKey source, std::function<void()> action);

	void Execute() const;

private:
	Window& m_context;
	EKey m_source;
	std::function<void()> m_action;
};