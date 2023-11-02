#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "shaders.hpp"
#include "shapes.hpp"
#include "gl.hpp"
#include "window.hpp"

#define WIN_WIDTH 1100
#define WIN_HEIGHT 600

void logVersionInfo() {
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported " << version << std::endl;
}

glm::mat4 getMVPMatrix(Shape *shape) {
    // (Change values)

    // [-1,1] -> [0,SIZE] mapping
    glm::mat4 Projection = glm::ortho(0.0f, (float) WIN_WIDTH, (float) WIN_HEIGHT, 0.0f);

    // Transformations
    glm::mat4 Model = glm::mat4(1.0);
    Model = glm::translate(Model, glm::vec3(50.0f,50.0f,0));
    Model = glm::scale(Model, glm::vec3(100.0f, 100.0f, 1.0f));

    return Projection * Model;
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

    const int numTriangles = 50;
    Shape shape = generateCircle(.0f, .0f, .5f, .5f, numTriangles);

    // Set up Vertex Array Object (VAO)
    GLuint vao = setupVAO();
    // Set up Vertex Buffer
    shape.verticesVbo = newBuffer(&shape.vertices.front(), shape.vertices.size() * sizeof(glm::vec3) * sizeof(GLfloat));
    // Set up Color Buffer
    shape.colorsVbo = newBuffer(&shape.colors.front(), shape.colors.size() * sizeof(glm::vec3) * sizeof(GLfloat));

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Dark blue background
    glClearColor(0.0f, 0.0f, 0.1f, 0.0f);

    // Load shaders
    GLuint shaders = loadShaders("../shaders/vertex.glsl", "../shaders/fragment.glsl");

    // Get a handle for our "MVP" uniform
    // Only during the initialisation
    GLint MatrixID = glGetUniformLocation(shaders, "MVP");

    do {
        // Applu shaders
        glUseProgram(shaders);

        glm::mat4 mvp = getMVPMatrix(&shape);

        // Send our transformation to the currently bound shader, in the "MVP" uniform
        // This is done in the main loop since each model will have a different MVP matrix (At least for the M part)
        glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &mvp[0][0]);

        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT);

        draw(shape.verticesVbo, shape.colorsVbo, shape.verticesAmount);

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (isAlive(window));

    // Cleanup VBO and shader
    glDeleteBuffers(1, &shape.verticesVbo);
    glDeleteBuffers(1, &shape.colorsVbo);
    glDeleteProgram(shaders);
    glDeleteVertexArrays(1, &vao);

    // Close GL context and any other GLFW resources
    glfwTerminate();
    return 0;
}
