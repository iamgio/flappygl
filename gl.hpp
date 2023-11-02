#ifndef FLAPPYGL_DRAW_H
#define FLAPPYGL_DRAW_H

#include <GL/glew.h>

void draw(GLuint vertexBuffer, GLuint colorBuffer, int vertexCount);

GLuint setupVAO();

GLuint newBuffer(const void *data, GLsizeiptr size);

#endif
