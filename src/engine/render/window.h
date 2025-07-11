#pragma once

#include <stdbool.h>

#include "../types.h"
#include "glfw3.h"

typedef struct {
  GLFWwindow *window;
  f32 width;
  f32 height;
} Window_State;

Window_State *window_create(int height, int width, const char *title);
void window_set_close(Window_State *window_state);
bool window_should_close(Window_State *window_state);
void window_poll_swap(Window_State *window_state); 
void window_destroy(Window_State *window_state);
