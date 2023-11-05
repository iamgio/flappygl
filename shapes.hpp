#include <GL/glew.h>
#include <vector>
#include "shape.hpp"

#ifndef FLAPPYGL_SHAPES_H
#define FLAPPYGL_SHAPES_H

#define PI 3.14159

#define SQRT2 1.4142

struct Point {
    float x, y, z;
};

Shape generateRectangle(float x, float y, float w, float h,
                        glm::vec3 topLeftColor, glm::vec3 topRightColor, glm::vec3 bottomLeftColor, glm::vec3 bottomRightColor);

Shape generateCircle(float cx, float cy, float rx, float ry, int numTriangles);

Shape generateHeart(float cx, float cy, int numTriangles);


Shape generateMoon(float cx, float cy, int numTriangles);

#endif