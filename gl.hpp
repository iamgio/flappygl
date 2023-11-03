#ifndef FLAPPYGL_DRAW_H
#define FLAPPYGL_DRAW_H

#include <GL/glew.h>

void backgroundColor(float r, float g, float b);

void draw(GLuint vertexBuffer, GLuint colorBuffer, int vertexCount, GLenum method);

GLuint setupVAO();

GLuint newBuffer(const void *data, GLsizeiptr size);

void updateMVP(glm::mat4 mvp, GLint mvpUniformID);

#endif
