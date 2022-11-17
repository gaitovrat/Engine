#include "FileUtil.hpp"

#include <fstream>
#include <sstream>

#include "Exception/FileException.hpp"

std::string FileUtil::Read(const char* filename)
{
    std::ifstream file(filename);
    if (file.is_open() == false)
    {
        throw FileException("Unable to open " + std::string(filename));;
    }

    std::stringstream stringStream;

    stringStream << file.rdbuf();

    return stringStream.str();
}
