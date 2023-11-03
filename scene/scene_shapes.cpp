#include "../shape.hpp"
#include "scene.h"

#define GROUND_HEIGHT 60
#define GROUND_COLOR_TOP 0.92f, 0.87f, 0.71f
#define GROUND_COLOR_BOTTOM 0.56f, 0.81f, 0.3f

Shape createGroundShape(Scene *scene) {
    Shape shape = Shape {
        .verticesAmount = 6,
        .trianglesAmount = 2
    };

    glm::vec3 topLeft = glm::vec3(0, scene->getHeight() - GROUND_HEIGHT, 0);
    glm::vec3 topRight = glm::vec3(scene->getWidth(), scene->getHeight() - GROUND_HEIGHT, 0);
    glm::vec3 bottomLeft = glm::vec3(0, scene->getHeight(), 0);
    glm::vec3 bottomRight = glm::vec3(scene->getWidth(), scene->getHeight(), 0);

    // Triangle 1
    shape.vertices.push_back(topLeft);
    shape.vertices.push_back(topRight);
    shape.vertices.push_back(bottomLeft);

    // Triangle 2
    shape.vertices.push_back(topRight);
    shape.vertices.push_back(bottomRight);
    shape.vertices.push_back(bottomLeft);

    glm::vec3 colorTop = glm::vec3(GROUND_COLOR_TOP);
    glm::vec3 colorBottom = glm::vec3(GROUND_COLOR_BOTTOM);

    shape.colors.push_back(colorBottom);
    shape.colors.push_back(colorBottom);
    shape.colors.push_back(colorTop);
    shape.colors.push_back(colorBottom);
    shape.colors.push_back(colorTop);
    shape.colors.push_back(colorTop);

    return shape;
}