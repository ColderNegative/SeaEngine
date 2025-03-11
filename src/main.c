#include <stdio.h>

#include "glfw3.h"
#include "engine/render/window.h"
#include "engine/global.h"

int main() {
    Window_State *window_state = window_create(800, 800, "Engine");

    global.window_state = window_state;

    while (!glfwWindowShouldClose(window_state->window)) {
        glfwSwapBuffers(window_state->window);
        glfwPollEvents();
    }

    window_destroy(global.window_state);

    return 0;
}