#pragma once

#include "src/engine/types.h"

typedef struct {
    u32 program_id;
    const char *vertex_source;
    const char *fragment_source;
} Shader;

Shader *shader_create(const char *vertex_source, const char *fragment_source);
const char *shader_load_file(const char *file_path);
void shader_destroy(Shader *shader);
