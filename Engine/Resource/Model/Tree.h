#pragma once

#include "Resource/DrawableObject.h"

class Tree final : public DrawableObject
{
public:
	Tree();

	Tree(Shader& shader);
};