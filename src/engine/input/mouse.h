#pragma once

#define GLFW_MOUSE_OFFSET 0x00034001

#include "src/engine/types.h"
#include "src/engine/render/window.h"

typedef enum {
    SEAMOUSE_NORMAL,
    SEAMOUSE_HIDDEN,
    SEAMOUSE_DISABLED, 
} SEAMOUSE_TYPE;

typedef struct {
    f64 xpos;
    f64 ypos;
} Mouse;

Mouse* mouse_create(Window_State *window);
void mouse_set_input_mode(SEAMOUSE_TYPE mouse_type, Window_State *window);
void mouse_poll_position(Mouse *mouse, Window_State *window);
void mouse_destroy(Mouse *mouse);
