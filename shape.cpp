#include "shape.hpp"

void freeShape(Shape shape) {
    glDeleteBuffers(1, &shape.verticesVbo);
    glDeleteBuffers(1, &shape.colorsVbo);
}
