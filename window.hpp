#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLFWwindow *setupWindow(const char *title, int width, int height);

void setupWindowProperties();

bool isAlive(GLFWwindow *window);

#endif
