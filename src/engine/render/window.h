#pragma once

#include <stdbool.h>

#include "src/engine/types.h"
#include "third_party/glfw/glfw3.h"

typedef struct {
  GLFWwindow *window;
  f32 width;
  f32 height;
} Window_State;

Window_State *window_create(u32 height, u32 width, const char *title);
void window_set_close(Window_State *window_state);
bool window_should_close(Window_State *window_state);
void window_poll_swap(Window_State *window_state); 
void window_destroy(Window_State *window_state);
