#pragma once

#include "ELightType.hpp"
#include "AbstractLight.hpp"

class SpotLight final : public AbstractLight
{
public:
	SpotLight();

	SpotLight(glm::vec3 position, glm::vec3 direction);

	~SpotLight() override = default;

	[[nodiscard]] ELightType Type() const override;
};
