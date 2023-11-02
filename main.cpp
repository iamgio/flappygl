#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "shaders.hpp"
#include "shapes.hpp"

#define WIN_WIDTH 700
#define WIN_HEIGHT 700

void setupWindowProperties() {
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

GLFWwindow *setupWindow() {
    GLFWwindow *window = glfwCreateWindow(WIN_WIDTH, WIN_HEIGHT, "OpenGL", nullptr, nullptr);
    if (!window) {
        std::cerr << "ERROR: could not open window with GLFW3" << std::endl;
        glfwTerminate();
        return nullptr;
    }
    glfwMakeContextCurrent(window);

    return window;
}

GLuint setupVAO() {
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    return VertexArrayID;
}

GLuint setupBuffer(const void *data, GLsizeiptr size) {
    GLuint buffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &buffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    return buffer;
}

void logVersionInfo() {
    const GLubyte *renderer = glGetString(GL_RENDERER);
    const GLubyte *version = glGetString(GL_VERSION);
    std::cout << "Renderer: " << renderer << std::endl;
    std::cout << "OpenGL version supported " << version << std::endl;
}

bool isAlive(GLFWwindow *window) {
    // Check if the ESC key was pressed or the window was closed
    return glfwGetKey(window, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(window);
}

glm::mat4 getMVPMatrix(Shape *shape) {
    // (Change values)

    // [-1,1] -> [0,SIZE] mapping
    glm::mat4 Projection = glm::ortho(0.0f, 100.0f, 0.0f, 100.0f);

    // Transformations
    glm::mat4 Model = glm::mat4(1.0);
    Model = glm::translate(Model, glm::vec3(50.0f,50.0f,0));
    Model = glm::scale(Model, glm::vec3(100.0f, 100.0f, 1.0f));

    return Projection * Model;
}

void draw(GLuint vertexBuffer, GLuint colorBuffer, int vertexCount) {
    // Draw stuff here...

    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,       // normalized
            0,      // stride
            nullptr            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                     // normalized?
            0,                                // stride
            nullptr                          // array buffer offset
    );

    // Draw the triangle
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
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
    GLFWwindow *window = setupWindow();
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
    shape.verticesVbo = setupBuffer(&shape.vertices.front(), shape.vertices.size() * sizeof(glm::vec3) * sizeof(GLfloat));
    // Set up Color Buffer
    shape.colorsVbo = setupBuffer(&shape.colors.front(), shape.colors.size() * sizeof(glm::vec3) * sizeof(GLfloat));

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
