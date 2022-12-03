#pragma once
#include <memory>

#include "EObserverEvent.hpp"

class IObserver;

class ISubject
{
public:
	virtual ~ISubject() = default;

	virtual void AddObserver(IObserver* observer) = 0;

	virtual void NotifyAll(EObserverEvent event) = 0;
};
