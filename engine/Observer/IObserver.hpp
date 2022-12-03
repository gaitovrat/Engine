#pragma once

#include "EObserverEvent.hpp"
#include "ISubject.hpp"

class IObserver
{
public:
	virtual void Notify(EObserverEvent event, ISubject* source) = 0;

	virtual ~IObserver() = default;
};
