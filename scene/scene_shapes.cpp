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


Shape createBirdShape() {
    glm::vec3 color = glm::vec3(0.5, 0.3, 0.2);
    return generateRectangle(-BIRD_SIZE / 2.0f, -BIRD_SIZE / 2.0f,
                             BIRD_SIZE, BIRD_SIZE,
                             color, color,
                             color, color);
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
    // TODO
    glm::vec3 color = glm::vec3(0);

    Shape shape = {.method = GL_TRIANGLE_FAN};

    float p0x = 0;
    float p0y = 20;
    float p1x = 120;
    float p1y = 60;
    float p2x = 300;
    float p2y = 30;

    float v0x = 40;
    float v0y = 120;
    float v1x = -100;
    float v1y = -100;
    float v2x = 50;
    float v2y = 30;

    auto v1 = hermite3(p0x, p0y, p1x, p1y, p2x, p2y, v0x, v0y, v1x, v1y, v2x, v2y);
    //auto v2 = hermite(p1x, p1y, p2x, p2y, v1x, v1y, v2x, v2y);

    //v1.insert(v1.end(), v2.begin(), v2.end());

    shape.vertices = v1;

    shape.vertices.push_back(glm::vec3(SCENE_WIDTH, 0, 0));
    shape.vertices.push_back(glm::vec3(0, 0, 0));

    shape.verticesAmount = shape.vertices.size();

    for (int i = 0; i < shape.verticesAmount; i++) {
        shape.colors.push_back(color);
    }

    return shape;
}