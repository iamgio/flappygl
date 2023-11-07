#ifndef FLAPPYGL_SHAPE_H
#define FLAPPYGL_SHAPE_H


#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>
#include "shader/shader.h"
#include "shader/program.h"

typedef struct {
    GLuint verticesVbo;
    GLuint colorsVbo;
    int verticesAmount;
    int trianglesAmount;
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> colors;
    glm::vec3 translation;
    glm::vec3 scale;
    float rotationAngle;
    //glm::vec3 rotationAxis;
    GLenum method;
    //Shader *vertexShader;
    //Shader *fragmentShader;
    Program *shaderProgram;
    std::vector<glm::vec3> CP;
} Shape;

void freeShape(Shape shape);

#endif