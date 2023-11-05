#ifndef FLAPPYGL_WINDOW_H
#define FLAPPYGL_WINDOW_H

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow *setupWindow(const char *title, int width, int height);

void setupWindowProperties();

bool isAlive(GLFWwindow *window);

bool isKeyPressed(GLFWwindow *window, int key);

#endif
