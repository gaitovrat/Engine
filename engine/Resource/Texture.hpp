#pragma once

#include "IResource.hpp"

class Texture final : public IResource
{
	Texture();

public:
	explicit Texture(std::string filepath);

	void Load(std::string filepath) override;

	void Bind() const;

	virtual ~Texture() = default;
private:
	uint32_t m_id;	
};