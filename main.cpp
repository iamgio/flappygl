#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "shaders.h"
#include "gl.h"
#include "window.h"
#include "settings.h"
#include "game/game.h"
#include "scene/scene.h"
#include "text/text.h"

#define WIN_WIDTH 1100
#define WIN_HEIGHT (WIN_WIDTH / ASPECT_RATIO)

#define SCORE_FONT_SCALE_IN_GAME 5.0f
#define SCORE_FONT_SCALE_ENDED 15.0f

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

    // GLText initialization
    //gltInit();

    // Get version info
    logVersionInfo();

    // Set up Vertex Array Object (VAO)
    GLuint vao = setupVAO();

    // Ensure we can capture the escape key being pressed below
    glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);

    // Load shaders
    Shaders shaders = loadShaders("../shaders/vertex.glsl", "../shaders/fragment.glsl");
    //Shaders groundShaders = loadShaders("../shaders/vertex.glsl", "../shaders/fragmentGround.glsl");

    // Get a handle for our "MVP" uniform
    // Only during the initialisation
    GLint MatrixID = shaders.getUniform("MVP");

    scene = new Scene(vao, MatrixID);
    game = new Game(scene);

    game->start();

    // Initialize glText
    gltInit();

    // Create score text
    Text *scoreText = new Text();

    do {
        // Apply shaders
        shaders.use();

        // Clear the screen.
        glClear(GL_COLOR_BUFFER_BIT);

        game->update();

        if (isKeyPressed(window, GLFW_KEY_SPACE)) {
            game->jump();
        }

        scene->draw();

        scoreText->setText(("Score: " + std::to_string(game->getScore())).c_str());

        // Draw score text, centered
        gltBeginDraw();
        gltDrawText2DAligned(scoreText->text,
                             WIN_WIDTH, .0f,
                             game->hasEnded() ? SCORE_FONT_SCALE_ENDED : SCORE_FONT_SCALE_IN_GAME,
                             GLT_CENTER, GLT_TOP);
        gltEndDraw();

        // Swap buffers
        glfwSwapBuffers(window);
        glfwPollEvents();
    } while (isAlive(window));

    // Cleanup VBO and shader
    shaders.del();
    glDeleteVertexArrays(1, &vao);

    // Close GL context and any other GLFW resources
    gltTerminate();
    scoreText->del();
    glfwTerminate();
    return 0;
}
