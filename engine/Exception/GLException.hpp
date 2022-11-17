#pragma once

#include <exception>
#include <string>

class GLException : public std::exception
{
public:
	GLException(std::string message);

	const char* what() const noexcept override;

private:
	std::string m_message;
};
