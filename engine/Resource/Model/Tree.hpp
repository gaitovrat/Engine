#pragma once

#include "Resource/DrawableObject.hpp"

class Tree final : public DrawableObject
{
public:
	Tree();

	Tree(Shader& shader);
};
