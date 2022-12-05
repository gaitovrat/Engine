#pragma once

#include "Resource/DrawableObject.hpp"

class Tree final : public DrawableObject
{
public:
	Tree();

	Tree(const std::shared_ptr<Shader>& shader);
};