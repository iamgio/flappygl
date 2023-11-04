#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "shaders.hpp"
#include "shapes.hpp"
#include "gl.hpp"
#include "window.hpp"
#include "settings.h"
#include "game/game.h"
#include "scene/scene.h"
#include "game/ground.h"
#include "game/bird.h"

#define WIN_WIDTH 1100
#define WIN_HEIGHT (WIN_WIDTH / ASPECT_RATIO)

static Game *game;
static Scene *scene;

void logVersionInfo() {
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported " << version << std::endl;
}

int main(int argc, char **argv) {
    // Start GL context and OS window using the GLFW helper library
    if (!glfwInit()) {
        std::cerr << "ERROR: could not start GLFW3" << std::endl;
        return 1;
    }

    // Set window properties
    setupWindowProperties();

    // Create the window
    GLFWwindow *window = setupWindow("FlappyGL", WIN_WIDTH, WIN_HEIGHT);
    if (!window) {
        return 1;
    }

    // Start GLEW extension handler
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        return 1;
    }

    // Get version info
    logVersionInfo();

    // Set up Vertex Array Object (VAO)
    GLuint vao = setupVAO();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Load shaders
    GLuint shaders = loadShaders("../shaders/vertex.glsl", "../shaders/fragment.glsl");

    // Get a handle for our "MVP" uniform
    // Only during the initialisation
    GLint MatrixID = glGetUniformLocation(shaders, "MVP");

    scene = new Scene(MatrixID);
    game = new Game(scene);

    game->start();

    game->addObject(new Ground());
    game->addObject(new Bird());

    do {
        // Applu shaders
        glUseProgram(shaders);

        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT);

        game->update();

        if (isKeyPressed(window, GLFW_KEY_SPACE)) {
            game->jump();
        }

        //draw(shape.verticesVbo, shape.colorsVbo, shape.verticesAmount);
        scene->draw();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (isAlive(window));

    // Cleanup VBO and shader
    //glDeleteBuffers(1, &shape.verticesVbo);
    //glDeleteBuffers(1, &shape.colorsVbo);
    //glDeleteProgram(shaders);
    //glDeleteVertexArrays(1, &vao);

    // Close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}
