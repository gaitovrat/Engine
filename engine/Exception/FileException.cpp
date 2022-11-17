#include "FileException.hpp"

FileException::FileException(std::string message)
{
	m_message = "[FileException]: " + message;
}

const char* FileException::what() const noexcept
{
	return m_message.c_str();
}
