#pragma once

class IComponent
{
public:
	virtual void Activate() = 0;
	virtual ~IComponent() = default;
};