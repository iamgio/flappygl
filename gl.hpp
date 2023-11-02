#ifndef __DRAW_H__
#define __DRAW_H__

#include <GL/glew.h>

void draw(GLuint vertexBuffer, GLuint colorBuffer, int vertexCount);

GLuint setupVAO();

GLuint newBuffer(const void *data, GLsizeiptr size);

#endif
