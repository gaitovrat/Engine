#include "Tree.hpp"

#include "Resource/ResourceManager.hpp"
#include "Raw/tree.hpp"
#include "Configuration.hpp"

Tree::Tree() : Tree(ResourceManager::GetInstance().GetShader(Configuration::defaultShader))
{
}

Tree::Tree(Shader& shader) : DrawableObject(tree, sizeof(tree) / sizeof(tree[0]), shader)
{
}
