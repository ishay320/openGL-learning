#ifndef MESH_H
#define MESH_H
#include <cstdint>

class Mesh
{
   private:
    float *_vertices;
    const uint8_t _vertex_block_size;
    unsigned int *_indices;
    int _sizeof_indices;
    unsigned int _VBO, _VAO, _EBO;

   public:
    Mesh(float *vertices, int vertices_number, const uint8_t vertex_block_size, unsigned int *indices, int sizeof_indices);

    ~Mesh();

    void draw();
    void deallocate();

    void bind();
};

#endif  // MESH_H