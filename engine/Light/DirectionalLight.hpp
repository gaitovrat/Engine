#pragma once

#include "ELightType.hpp"
#include "AbstractLight.hpp"

class DirectionalLight : public AbstractLight
{
public:
	DirectionalLight();

	explicit DirectionalLight(glm::vec3 direction);

	~DirectionalLight() override = default;

	[[nodiscard]] ELightType Type() const override;
};
