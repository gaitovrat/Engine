#pragma once

#include "EObserverEvent.hpp"

class IObserver
{
public:
	virtual void Notify(EObserverEvent event) = 0;
};
