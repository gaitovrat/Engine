#include "VertexBuffer.hpp"

#include <GL/glew.h>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include <utility>



VertexBuffer::VertexBuffer() : VertexBuffer(std::vector<Vertex>())
{
}

VertexBuffer::VertexBuffer(const std::string& filepath) : VertexBuffer()
{
    Load(filepath);
}

VertexBuffer::VertexBuffer(std::vector<Vertex> vertices) : m_vao(0), m_ibo(0), m_vertexCount(0), m_data(std::move(vertices)), m_hasIndexes(false)
{
    m_vertexCount = m_data.size();
    Init();
}

void VertexBuffer::Init()
{
	if (m_data.empty())
	{
		return;
	}

    constexpr int offsets[] = { 0, (3 * sizeof(float)), (6 * sizeof(float)), (8 * sizeof(float)) };
    constexpr int sizes[] = { 3, 3, 2, 3 };
    constexpr int size = 4;

	uint32_t vbo(0);
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, m_data.size() * sizeof(m_data[0]), &m_data.front(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &m_vao);
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);

	for (int i = 0; i < size; ++i)
	{
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(i, sizes[i], GL_FLOAT, GL_FALSE, sizeof(m_data[0]), (void*)(offsets[i]));
	}
}

void VertexBuffer::Bind() const
{
	glBindVertexArray(m_vao);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
}

void VertexBuffer::SetData(const std::vector<Vertex>& vertices)
{
	m_data = vertices;
	Init();
}

void VertexBuffer::SetIndicies(unsigned* indicies, int size)
{
	glGenBuffers(1, &m_ibo);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_ibo);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indicies, GL_STATIC_DRAW);
}

void VertexBuffer::Load(const std::string& filepath)
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
            m_hasIndexes = true;
            indices = new unsigned int[mesh->mNumFaces * 3];
            for (unsigned int i = 0; i < mesh->mNumFaces; i++)
            {
                indices[i * 3] = mesh->mFaces[i].mIndices[0];
                indices[i * 3 + 1] = mesh->mFaces[i].mIndices[1];
                indices[i * 3 + 2] = mesh->mFaces[i].mIndices[2];
            }
            SetIndicies(indices, sizeof(GLuint) * mesh->mNumFaces * 3);
            delete[] indices;
        }


        SetData(vertices);
        m_vertexCount = mesh->mNumFaces * 3;
    }
}

bool VertexBuffer::HasIndexes() const
{
    return m_hasIndexes;
}

uint32_t VertexBuffer::VertexCount() const
{
    return m_vertexCount;
}
