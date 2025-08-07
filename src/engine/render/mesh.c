#include <stdlib.h>

#include "glad/glad.h"
#include "src/engine/types.h"
#include "mesh.h"

Mesh *mesh_create(Array *vertices, Array *indices) {
    u32 vao_id, vbo_id, ebo_id;
    glGenVertexArrays(1, &vao_id);
    glBindVertexArray(vao_id);

    glGenBuffers(1, &vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_id);
    glBufferData(GL_ARRAY_BUFFER, vertices->element_size*vertices->size, vertices->elements, GL_STATIC_DRAW);

    glGenBuffers(1, &ebo_id);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo_id);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->element_size*indices->size, indices->elements, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, vertices->element_size, (void*)0);
    glEnableVertexAttribArray(0);
    glBindVertexArray(0);

    Mesh *mesh = malloc(sizeof(*mesh));
    *mesh = (Mesh) {
        .vao_id = vao_id,
        .vertices = vertices,
        .indices = indices,
    };

    return mesh;
}

void mesh_draw(Mesh *mesh, Shader *shader) {
    glUseProgram(shader->program_id);
    glBindVertexArray(mesh->vao_id);
    glDrawElements(GL_TRIANGLES, mesh->indices->size, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

void mesh_destroy(Mesh *mesh) {
    free(mesh->vertices);
    free(mesh->indices);
    free(mesh);
}


