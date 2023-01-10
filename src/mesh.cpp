
#include <glad/glad.h>
// put GLFW after glad
#include <GLFW/glfw3.h>

#include "mesh.h"

Mesh::Mesh(float *vertices, int sizeof_vertices, const uint8_t vertex_block_size, unsigned int *indices, int sizeof_indices) : _vertices(vertices), _vertex_block_size(vertex_block_size), _indices(indices), _sizeof_indices(sizeof_indices)
{
    glGenVertexArrays(1, &_VAO);
    glGenBuffers(1, &_VBO);
    glGenBuffers(1, &_EBO);

    // vertices array
    glBindVertexArray(_VAO);

    // vertices buffer
    glBindBuffer(GL_ARRAY_BUFFER, _VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof_vertices, vertices, GL_STATIC_DRAW);

    // element buffer
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof_indices, _indices, GL_STATIC_DRAW);

    //// vertices attribute pointer
    // vertices
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertex_block_size * sizeof(float), (void *)(0 * sizeof(float)));
    glEnableVertexAttribArray(0);
    // color
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, vertex_block_size * sizeof(float), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    // texture
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, vertex_block_size * sizeof(float), (void *)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    glBindVertexArray(0);

    // uncomment this call to draw in wireframe polygons.
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
}

Mesh::~Mesh() {}

void Mesh::draw()
{
    bind();
    // render
    const unsigned long vertices_to_render = _sizeof_indices / sizeof(*_indices);
    glDrawElements(GL_TRIANGLES, vertices_to_render, GL_UNSIGNED_INT, 0);
    // glBindVertexArray(0); // no need to unbind it every time
}

void Mesh::deallocate()
{
    glDeleteVertexArrays(1, &_VAO);
    glDeleteBuffers(1, &_VBO);
}

void Mesh::bind() { glBindVertexArray(_VAO); }
