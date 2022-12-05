#include "Tree.hpp"

#include "Resource/ResourceManager.hpp"
#include "RawModel/tree.h"

Tree::Tree() : Tree(ResourceManager::GetInstance().GetShader("constant"))
{
}

Tree::Tree(const std::shared_ptr<Shader>& shader) : DrawableObject(std::make_shared<VertexBuffer>(Vertex::ToVector(tree, sizeof(tree) / sizeof(float), Vertex::NORMAL)), shader)
{
}
