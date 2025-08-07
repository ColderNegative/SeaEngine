#pragma once

#include "src/engine/array.h"
#include "src/engine/render/shader.h"
#include "src/engine/types.h"

typedef struct {
    u32 vao_id;
    Array *vertices; 
    Array *indices;
} Mesh;

Mesh *mesh_create(Array *vertices, Array *indices);
void mesh_draw(Mesh *mesh, Shader *shader);
void mesh_destroy(Mesh *mesh);
