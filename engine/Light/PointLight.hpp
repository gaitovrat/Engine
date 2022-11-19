#pragma once

#include "AbstractLight.hpp"

class PointLight final : public AbstractLight
{
public:
	PointLight();

	~PointLight() override = default;
	
	[[nodiscard]] ELightType Type() const override;
};
