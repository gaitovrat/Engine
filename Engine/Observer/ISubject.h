#pragma once
#include "IObserver.h"
#include "EObserverEvent.h"

class ISubject
{
public:
	virtual void AddObserver(IObserver* observer) = 0;
	virtual void NotifyAll(EObserverEvent event) = 0;
};
