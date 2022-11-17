#pragma once

#include <exception>
#include <string>

class GLFWException : public std::exception
{
public:
	GLFWException(std::string message);

	const char* what() const noexcept override;

private:
	std::string m_message;
};
