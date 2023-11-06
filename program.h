#ifndef FLAPPYGL_PROGRAM_H
#define FLAPPYGL_PROGRAM_H

#include <GL/glew.h>
#include "shader.h"

class Program {
private:
    GLuint program;
public:
    Program(GLuint program);

    GLuint getID();

    GLint getUniform(const char *name);

    void use();
    void del();

    void attachShader(Shader *shader);
    void detachShader(Shader *shader);

    void link();
};

Program createProgram();

#endif
