#include "Tree.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/tree.hpp"

Tree::Tree() : Tree(ResourceManager::GetInstance().GetShader("1"))
{
}

Tree::Tree(Shader& shader) : DrawableObject(tree, sizeof(tree) / sizeof(tree[0]), shader)
{
}
