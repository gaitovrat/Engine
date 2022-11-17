#pragma once

#include <cstdint>

#include "EShaderType.hpp"
#include "Util/ShaderUtil.hpp"

class BaseShader
{
public:
	BaseShader(const char* filename, EShaderType type);

	virtual ~BaseShader() = default;

	void Compile() const;

	void AttachToProgram(uint32_t programId) const;

private:
	uint32_t m_id;
};
