#include "DrawableObject.hpp"

#include <assimp/Importer.hpp>
#include <assimp/scene.h>// aiSceneoutputdata structure
#include <assimp/postprocess.h>// Post processingflags

#include "ResourceManager.hpp"

DrawableObject::DrawableObject(const std::shared_ptr<Shader> shader, const Texture& texture) : DrawableObject(std::vector<Vertex>(), shader, texture)
{
}

DrawableObject::DrawableObject() : DrawableObject(ResourceManager::GetInstance().GetShader("texture"), *ResourceManager::GetInstance().GetTexture("box.jpg"))
{
}

DrawableObject::DrawableObject(const std::vector<Vertex>& vertecies, const std::shared_ptr<Shader> shader, const Texture& texture) :
	m_vertexCount(vertecies.size()), m_vertexBuffer(vertecies), m_shader(shader), m_texture(texture)
{
}

DrawableObject::DrawableObject(const std::string& filepath, const std::shared_ptr<Shader> shader, const Texture& texture) : DrawableObject(shader, texture)
{
    Load(filepath);
}

void DrawableObject::Activate()
{
    m_shader->Activate();
    m_shader->SetModelMatrix(m_transformation.GetMatrix());
	m_transformation.Activate();
    m_shader->UpdateUniforms();
    m_vertexBuffer.Bind();
    m_texture.Bind();
}

uint32_t DrawableObject::GetVertexCount() const
{
	return m_vertexCount;
}

Transformation& DrawableObject::GetTransformation()
{
	return m_transformation;
}

std::shared_ptr<Shader> DrawableObject::GetShader()
{
    return m_shader;
}

const std::shared_ptr<Shader> DrawableObject::GetCShader() const
{
    return m_shader;
}

Texture& DrawableObject::GetTexture()
{
    return m_texture;
}

const Texture& DrawableObject::GetCTexture() const
{
    return m_texture;
}

void DrawableObject::SetShader(const std::shared_ptr<Shader> shader)
{
    m_shader = shader;
}

void DrawableObject::SetTexture(const Texture& texture)
{
    m_texture = texture;
}

void DrawableObject::Load(const std::string& filepath)
{
    Assimp::Importer importer;
    constexpr unsigned int importOptions = aiProcess_OptimizeMeshes
        | aiProcess_JoinIdenticalVertices
        | aiProcess_Triangulate
        | aiProcess_CalcTangentSpace;

    const aiScene* scene = importer.ReadFile(filepath, importOptions);

    if (scene) {
        printf("scene->mNumMeshes = %d\n", scene->mNumMeshes);
        printf("scene->mNumMaterials = %d\n", scene->mNumMaterials);


        const aiMesh* mesh = scene->mMeshes[0];

        std::vector<Vertex> vertices(mesh->mNumVertices);

        for (unsigned int j = 0; j < mesh->mNumVertices; j++)
        {
            if (mesh->HasPositions())
            {
                vertices[j].position[0] = mesh->mVertices[j].x;
                vertices[j].position[1] = mesh->mVertices[j].y;
                vertices[j].position[2] = mesh->mVertices[j].z;
            }
            if (mesh->HasNormals())
            {
                vertices[j].normal[0] = mesh->mNormals[j].x;
                vertices[j].normal[1] = mesh->mNormals[j].y;
                vertices[j].normal[2] = mesh->mNormals[j].z;
            }
            if (mesh->HasTextureCoords(0))
            {
                vertices[j].texture[0] = mesh->mTextureCoords[0][j].x;
                vertices[j].texture[1] = mesh->mTextureCoords[0][j].y;
            }
            if (mesh->HasTangentsAndBitangents())
            {
                vertices[j].tangent[0] = mesh->mTangents[j].x;
                vertices[j].tangent[1] = mesh->mTangents[j].y;
                vertices[j].tangent[2] = mesh->mTangents[j].z;
            }
        }

        unsigned int* indices = nullptr;
        if (mesh->HasFaces())
        {

            indices = new unsigned int[mesh->mNumFaces * 3];
            for (unsigned int i = 0; i < mesh->mNumFaces; i++)
            {
                indices[i * 3] = mesh->mFaces[i].mIndices[0];
                indices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
                indices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
            }
            m_vertexBuffer.SetIndicies(indices, sizeof(GLuint) * mesh->mNumFaces * 3);
            delete[] indices;
        }

        m_vertexBuffer.SetData(vertices);
        m_vertexCount = mesh->mNumFaces * 3;
    }
}
