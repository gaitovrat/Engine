#include "GLFWException.hpp"

GLFWException::GLFWException(std::string message)
{
	m_message = "[GLFWException]: " + message;
}

const char* GLFWException::what() const noexcept
{
	return m_message.c_str();
}
