#pragma once

#include "../types.h"
#include "glfw3.h"

typedef struct {
  GLFWwindow *window;
  f32 width;
  f32 height;
} Window_State;

Window_State *window_create(int height, int width, const char *title);
void window_destroy();