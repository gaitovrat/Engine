#pragma once

#include <exception>
#include <string>

class FileException : public std::exception
{
public:
	FileException(std::string message);

	const char* what() const noexcept override;

private:
	std::string m_message;
};
