#include <stdio.h>
#include <stdlib.h>

#include "../util.h"
#include "glad/glad.h"
#include "glfw3.h"
#include "window.h"

static void framebuffer_resize_callback(GLFWwindow *window, int width,
                                        int height);
Window_State *window_create(u32 height, u32 width, const char *title) {
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

  GLFWwindow *window = glfwCreateWindow(800, 800, title, NULL, NULL);
  if (window == NULL) {
    glfwTerminate();
    ERROR_EXIT("glfw failed to create window");
  }
  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    glfwTerminate();
    ERROR_EXIT("failed to load glad");
  }

  glViewport(0, 0, 800, 800);
  glfwSetFramebufferSizeCallback(window, framebuffer_resize_callback);

  LOG_INFO("GL Vendor: %s", glGetString(GL_VENDOR));
  LOG_INFO("info (window): GL Renderer: %s", glGetString(GL_RENDERER));
  LOG_INFO("info (window): GL Version: %s", glGetString(GL_VERSION));

  Window_State *window_state = malloc(sizeof(*window_state));

  *window_state = (Window_State) {
    .window = window,
    .height = height,
    .width = width,
  };

  return window_state;
}

void window_set_close(Window_State *window_state) {
    glfwSetWindowShouldClose(window_state->window, GLFW_TRUE);
    return;
}

bool window_should_close(Window_State *window_state) {
    return glfwWindowShouldClose(window_state->window);
};

void window_poll_swap(Window_State *window_state) {
    glfwSwapBuffers(window_state->window); 
    glfwPollEvents();
};

void window_destroy(Window_State *window_state) { 
    glfwDestroyWindow(window_state->window);
    glfwTerminate(); 
    free(window_state);
}

static void framebuffer_resize_callback(GLFWwindow *window, int width,
                                        int height) {
  glViewport(0, 0, width, height);
}

