#include "GLException.h"

GLException::GLException(std::string message)
{
	m_message = "[GLException]: " + message;
}

const char* GLException::what() const noexcept
{
	return m_message.c_str();
}
