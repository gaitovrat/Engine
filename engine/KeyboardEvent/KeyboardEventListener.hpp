#pragma once

#include <functional>

#include "Window.hpp"
#include "EKey.hpp"

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
