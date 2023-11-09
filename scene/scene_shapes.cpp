#include <iostream>
#include "../shape.h"
#include "scene.h"
#include "../game/ground.h"
#include "../shapes.h"
#include "../game/pipe.h"
#include "../game/bird.h"
#include "../game/background_details.h"
#include "../hermite.h"

#define GROUND_COLOR_TOP 0.5f, 0.7f, 0.3f
#define GROUND_COLOR_BOTTOM 0.92f, 0.87f, 0.71f

#define PIPE_COLOR_TOP 0.4f, 0.67f, 0.35f
#define PIPE_COLOR_BOTTOM 0.37f, 0.53f, 0.23f
#define PIPE_COLOR_RIGHT 0.1f, 0.25f, 0.1f

#define PIPE_TOP_WIDTH_OFFSET 2
#define PIPE_TOP_HEIGHT 5

#define BIRD_BORDER_COLOR 0.84f, 0.41f, 0.05f
#define BIRD_CENTER_COLOR 0.65f, 0.66f, 0.15f
#define BIRD_BORDER_SIZE 5

#define BACKGROUND_MOUNTAINS_BASE_HEIGHT 40


Shape createBirdShape() {
    glm::vec3 border = glm::vec3(BIRD_BORDER_COLOR);
    glm::vec3 center = glm::vec3(BIRD_CENTER_COLOR);

    Shape shape = {.method = GL_TRIANGLE_FAN};

    float vertexPos = BIRD_SIZE / 2.0f;

    shape.vertices = hermite3(
            -vertexPos, -vertexPos - 2.0f,
            vertexPos, .0f,
            -vertexPos, vertexPos,
            -10, 10,
            10, 0,
            -10, -10
    );

    shape.verticesAmount = shape.vertices.size();

    for (int i = 0; i < shape.verticesAmount; i++) {
        shape.colors.push_back(i % BIRD_BORDER_SIZE ? border : center);
    }

    return shape;
};

Shape createGroundShape() {
    glm::vec3 colorTop = glm::vec3(GROUND_COLOR_TOP);
    glm::vec3 colorBottom = glm::vec3(GROUND_COLOR_BOTTOM);
    return generateRectangle(
            0, 0,
            SCENE_WIDTH, GROUND_HEIGHT,
            colorTop, colorTop,
            colorBottom, colorBottom);
}

Shape createPipeShape(int type, float height) {
    glm::vec3 colorTop = glm::vec3(PIPE_COLOR_TOP);
    glm::vec3 colorBottom = glm::vec3(PIPE_COLOR_BOTTOM);
    glm::vec3 colorRight = glm::vec3(PIPE_COLOR_RIGHT);

    // The base (big rectangle) part
    Shape base = generateRectangle(
            -PIPE_WIDTH / 2.0f, type == SKY_PIPE ? -height : 0,
            PIPE_WIDTH, height - PIPE_TOP_HEIGHT,
            colorBottom, colorRight,
            colorTop, colorRight);

    // The end (small rectangle) part
    Shape top = generateRectangle(
            -(PIPE_WIDTH + PIPE_TOP_WIDTH_OFFSET) / 2.0f, (type == SKY_PIPE ? 0 : height) - PIPE_TOP_HEIGHT,
            PIPE_WIDTH + 2, PIPE_TOP_HEIGHT,
            colorBottom, colorRight,
            colorTop, colorRight);

    // Merge parts

    top.verticesAmount += 6;
    top.trianglesAmount += 2;

    top.vertices.insert(top.vertices.end(), base.vertices.begin(), base.vertices.end());
    top.colors.insert(top.colors.end(), base.colors.begin(), base.colors.end());

    if (type == SKY_PIPE) {
        // Flip vertically
        top.scale = glm::vec3(1, -1, 1);
    }

    return top;
}

Shape createBackgroundDetailsShape() {
    glm::vec3 color = glm::vec3(0); // Overridden by shaders

    Shape shape = {.method = GL_TRIANGLE_FAN};

    shape.vertices = hermite5(
            0, BACKGROUND_MOUNTAINS_BASE_HEIGHT,
            SCENE_WIDTH / 3.0f, BACKGROUND_MOUNTAINS_BASE_HEIGHT - 30,
            SCENE_WIDTH / 2.0f, BACKGROUND_MOUNTAINS_BASE_HEIGHT + 20,
            SCENE_WIDTH / 1.5f, BACKGROUND_MOUNTAINS_BASE_HEIGHT - 10,
            SCENE_WIDTH, BACKGROUND_MOUNTAINS_BASE_HEIGHT,
            100, 100,
            -50, 180,
            50, -50,
            -100, 300,
            100, -50
            );

    // Close the shape
    shape.vertices.insert(shape.vertices.begin(), glm::vec3(0, 0, 0));
    shape.vertices.push_back(glm::vec3(SCENE_WIDTH, 0, 0));

    shape.verticesAmount = shape.vertices.size();

    for (int i = 0; i < shape.verticesAmount; i++) {
        shape.colors.push_back(color);
    }

    return shape;
}