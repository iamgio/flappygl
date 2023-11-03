#include "../shape.hpp"
#include "scene.h"
#include "../game/ground.h"
#include "../shapes.hpp"

#define GROUND_COLOR_TOP 0.92f, 0.87f, 0.71f
#define GROUND_COLOR_BOTTOM 0.56f, 0.81f, 0.3f

Shape createBirdShape(Scene *scene) {
    glm::vec3 color = glm::vec3(0.5, 0.3, 0.2);
    return generateRectangle(0, 0, 30, 30, color, color, color, color);
};

Shape createGroundShape(Scene *scene) {
    glm::vec3 colorTop = glm::vec3(GROUND_COLOR_TOP);
    glm::vec3 colorBottom = glm::vec3(GROUND_COLOR_BOTTOM);
    return generateRectangle(
            0, 0,
            scene->getWidth(), GROUND_HEIGHT,
            colorTop, colorTop,
            colorBottom, colorBottom);
}