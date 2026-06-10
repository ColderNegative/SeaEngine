#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include "shader.h"
#include "third_party/glad/glad.h"
#include "src/engine/util.h"
#include "src/engine/types.h"

Shader *shader_create(const char *vertex_source, const char *fragment_source) {
    i32 success;
    char info_log[512];

    u32 vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex_shader, 1, &vertex_source, NULL);
    glCompileShader(vertex_shader);

    glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertex_shader, 512, NULL, info_log);
        ERROR_RETURN(NULL, "vertex shader failed to compile: %s", info_log);
    }

    u32 fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment_shader, 1, &fragment_source, NULL);
    glCompileShader(fragment_shader);

    glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragment_shader, 512, NULL, info_log);
        ERROR_RETURN(NULL, "fragment shader failed to compile: %s", info_log);
    }

    u32 program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);
    glLinkProgram(program_id);

    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(program_id, 512, NULL, info_log);
        ERROR_RETURN(NULL, "shader program failed to link: %s", info_log);
    }

    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);

    Shader *shader = malloc(sizeof(*shader));

    *shader = (Shader) {
        .program_id = program_id,
        .vertex_source = vertex_source,
        .fragment_source = fragment_source,
    };

    return shader;
}

const char *shader_load_file(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    char info_log[512];

    if (!file) {
        strerror_r(errno, info_log, 512);
        fclose(file);
        ERROR_RETURN(NULL, "shader failed to load file %s: %s", file_path, info_log);
    }

    fseek(file, 0, SEEK_END);
    i64 file_size = ftell(file);
    rewind(file);

    char *buffer = malloc(file_size);

    if (!fread(buffer, 1, file_size, file)) {
        fclose(file);
        ERROR_RETURN(NULL, "shader file failed to read into buffer: %s", file_path);
    }

    LOG_INFO("shader file read successfully:\n%s", buffer);

    fclose(file);
    
    return buffer;
}

void shader_destroy(Shader *shader) {
    glDeleteProgram(shader->program_id);
    free(shader);
}
