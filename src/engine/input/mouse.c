#include <stdlib.h>

#include "glfw3.h"
#include "src/engine/input/mouse.h"
#include "src/engine/types.h"

Mouse* mouse_create(Window_State *window) {
    Mouse *mouse = malloc(sizeof(*mouse));

    f64 xpos, ypos;
    glfwGetCursorPos(window->window, &xpos, &ypos);

    *mouse = (Mouse) {
        .xpos = xpos,
        .ypos = ypos,
    };
    
    return mouse;
}

void mouse_set_input_mode(SEAMOUSE_TYPE mouse_type, Window_State *window) {
    glfwSetInputMode(window->window, GLFW_CURSOR, mouse_type + GLFW_MOUSE_OFFSET);
}

void mouse_poll_position(Mouse *mouse, Window_State *window) {
    glfwGetCursorPos(window->window, &mouse->xpos, &mouse->ypos);
}

void mouse_destroy(Mouse *mouse) {
    free(mouse);
}
