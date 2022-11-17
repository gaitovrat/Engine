#pragma once
#include "IObserver.hpp"
#include "EObserverEvent.hpp"

class ISubject
{
public:
	virtual void AddObserver(IObserver* observer) = 0;
	virtual void NotifyAll(EObserverEvent event) = 0;
};
