#include "ShaderUtil.h"

#include <GL/glew.h>

std::string ShaderUtil::GetInfo(const uint32_t id)
{
    int32_t size;
    glGetProgramiv(id, GL_INFO_LOG_LENGTH, &size);

    if (size == 0)
    {
        return "";
    }
    
    char* info = new char[size + 1];
    glGetProgramInfoLog(id, size, NULL, info);

    std::string out(info);
    delete[] info;

    return out;
}
