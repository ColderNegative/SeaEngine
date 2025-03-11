#include <stdio.h>
#include <stdlib.h>

#include "../util.h"
#include "glad/glad.h"
#include "glfw3.h"
#include "window.h"

static void framebuffer_resize_callback(GLFWwindow *window, int width,
                                        int height);

Window_State *window_create(int height, int width, const char *title) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *window = glfwCreateWindow(800, 800, "Engine", NULL, NULL);
  if (window == NULL) {
    glfwTerminate();
    ERROR_EXIT("error: glfw failed to create window");
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
    ERROR_EXIT("error: failed to load glad");
  }

  glViewport(0, 0, 800, 800);
  glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

  printf("info (window): GL Vendor: %s\n", glGetString(GL_VENDOR));
  printf("info (window): GL Renderer: %s\n", glGetString(GL_RENDERER));
  printf("info (window): GL Version: %s\n", glGetString(GL_VERSION));

  Window_State *window_state = malloc(sizeof(*window_state));

  *window_state = (Window_State) {
    .window = window,
    .height = height,
    .width = width,
  };

  return window_state;
}

void window_destroy(Window_State *window_state) { 
    free(window_state);
    glfwTerminate(); 
}

static void framebuffer_resize_callback(GLFWwindow *window, int width,
                                        int height) {
  glViewport(0, 0, width, height);
}