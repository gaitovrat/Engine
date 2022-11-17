#include "Tree.h"

#include "Resource/ResourceManager.h"
#include "Raw/tree.h"

Tree::Tree() : Tree(ResourceManager::GetInstance().GetShader("1"))
{
}

Tree::Tree(Shader& shader) : DrawableObject(tree, sizeof(tree) / sizeof(tree[0]), shader)
{
}
