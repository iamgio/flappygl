#include <GL/glew.h>
#include <vector>
#include "shape.hpp"

#define PI 3.14159

struct Point {
    float x, y, z;
};

Shape generateCircle(float cx, float cy, float rx, float ry, int numTriangles);

Shape generateHeart(float cx, float cy, int numTriangles);


Shape generateMoon(float cx, float cy, int numTriangles);