#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

#ifndef __SHAPE_H__
#define __SHAPE_H__

typedef struct {
    GLuint verticesVbo;
    GLuint colorsVbo;
    int verticesAmount;
    int trianglesAmount;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> colors;
    glm::vec3 translation;
    glm::vec3 scale;
} Shape;

#endif