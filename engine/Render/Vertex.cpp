#include "Vertex.hpp"

std::vector<Vertex> Vertex::ToVector(const float* arr, int size, RowSize rowSize)
{
	std::vector<Vertex> vertecies;

	for (int i = 0, lastI = 0; i < size; i += rowSize, lastI = i)
	{
		Vertex vertex{};

		if (rowSize >= POSITION)
		{
			for (int j = 0; j < 3; j++)
			{
				vertex.position[j] = arr[lastI + j];
			}
			lastI += 3;
		}
		if (rowSize >= NORMAL)
		{
			for (int j = 0; j < 3; j++)
			{
				vertex.normal[j] = arr[lastI + j];
			}
			lastI += 3;
		}
		if (rowSize >= TEXTURE)
		{
			for (int j = 0; j < 2; j++)
			{
				vertex.texture[j] = arr[lastI + j];
			}
			lastI += 2;
		}
		if (rowSize >= TANGENT)
		{
			for (int j = 0; j < 3; j++)
			{
				vertex.tangent[j] = arr[lastI + j];
			}
			lastI += 3;
		}

		vertecies.push_back(vertex);
	}

	return vertecies;
}
