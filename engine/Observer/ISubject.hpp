#pragma once
#include <memory>

#include "EObserverEvent.hpp"

class IObserver;

class ISubject
{
public:
	virtual ~ISubject() = default;

	virtual void AddObserver(const std::shared_ptr<IObserver>& observer) = 0;

	virtual void NotifyAll(EObserverEvent event) = 0;
};
