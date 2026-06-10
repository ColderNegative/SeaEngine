#include <stdio.h>

#include "third_party/glad/glad.h"
#include "src/engine/render/mesh.h"
#include "src/engine/render/shader.h"
#include "src/engine/array.h"
#include "src/engine/render/window.h"
#include "src/engine/input/keyboard.h"
#include "src/engine/input/mouse.h"
#include "src/engine/util.h"
#include "third_party/cglm/cglm.h"

const char *vertex_shader_source = "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
    "}\0";

const char *fragment_shader_source = "#version 330 core\n"
    "out vec4 frag_color;\n"
    "void main()\n"
    "{\n"
    "   frag_color = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
    "}\0";


void test_key_callback(SEAKEY_STATE state, void *context) {
    if (state == SEAKEY_PRESS) {
        Window_State *window_state = (Window_State*) context;
        window_set_close(window_state);
        LOG_INFO("key pressed");
    }
}

int main() {
    Window_State *window_state = window_create(800, 800, "Engine");
    Keyboard_Input *keyboard_input = keyboard_create();
    Mouse *mouse = mouse_create(window_state);

    const char *simple_vert_source = read_file("assets/shaders/simple_vert.glsl");
    const char *simple_frag_source = read_file("assets/shaders/simple_frag.glsl");

    Shader *shader = shader_create(simple_vert_source, simple_frag_source);

    Array *vertices = array_create(3, sizeof(vec3));
    array_push(vertices, (vec3){-0.5, -0.5, 0.0});
    array_push(vertices, (vec3){0.5, -0.5, 0.0});
    array_push(vertices, (vec3){0.0, 0.5, 0.0});

    Array *indices = array_create(3, sizeof(u32));
    u32 a, b, c;
    a = 0;
    b = 1;
    c = 2;
    array_push(indices, &a);
    array_push(indices, &b);
    array_push(indices, &c);

    Mesh *triangle = mesh_create(vertices, indices);

    keyboard_register_key(keyboard_input, SEAKEY_Q, test_key_callback, window_state);

    while (!window_should_close(window_state)) {
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        mesh_draw(triangle, shader);

        window_poll_swap(window_state);
        keyboard_poll_keys(keyboard_input, window_state);
        mouse_poll_position(mouse, window_state);
    }

    mesh_destroy(triangle);

    keyboard_deregister_key(keyboard_input, SEAKEY_Q);

    keyboard_destroy(keyboard_input);
    window_destroy(window_state);
    mouse_destroy(mouse);

    return 0;
}


