#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "window.hpp"


GLFWwindow *setupWindow(const char *title, int width, int height) {
    GLFWwindow *window = glfwCreateWindow(width, height, title, nullptr, nullptr);
    if (!window) {
        std::cerr << "ERROR: could not open window with GLFW3" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);

    // Keep aspect ratio
    glfwSetWindowAspectRatio(window, width, height);

    return window;
}

void setupWindowProperties() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

bool isAlive(GLFWwindow *window) {
    // Check if the ESC key was pressed or the window was closed
    return !isKeyPressed(window, GLFW_KEY_ESCAPE) && !glfwWindowShouldClose(window);
}

bool isKeyPressed(GLFWwindow *window, int key) {
    return glfwGetKey(window, key) == GLFW_PRESS;
}
