#pragma once

#include <vector>

struct Vertex
{
    float position[3];
    float normal[3];
    float texture[2];
    float tangent[3];

    enum RowSize
    {
        POSITION = 3,
        NORMAL = 6,
        TEXTURE = 8,
        TANGENT = 11
    };

    static std::vector<Vertex> ToVector(const float* arr, int size, RowSize rowSize);
};