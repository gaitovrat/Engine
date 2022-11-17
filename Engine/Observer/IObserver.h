#pragma once

#include "EObserverEvent.h"

class IObserver
{
public:
	virtual void Notify(EObserverEvent event) = 0;
};
