#include "ArgumentsUtil.hpp"

#include <cstring>

void ArgumentsUtil::Parse(const int argc, const char** argv, int& width, int& height)
{
    if (argc < 2)
    {
        return;
    }
    
    for (int i = 1; i < argc; i += 2)
    {
        if (strcmp(argv[i], "-width") == 0)
        {
            width = atoi(argv[i + 1]);
        } 
        else if (strcmp(argv[i], "-height") == 0)
        {
            height = atoi(argv[i + 1]);
        }
    }
}
