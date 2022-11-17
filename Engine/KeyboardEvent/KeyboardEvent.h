#pragma once

#include <vector>

#include "KeyboardEventListener.h"

class KeyboardEvent final
{
public:
	void AddListener(const KeyboardEventListener& listener);

	void Dispath() const;

	static KeyboardEvent& GetInstance();

private:
	std::vector<KeyboardEventListener> m_listeners;
};