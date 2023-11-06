#ifndef FLAPPYGL_PROGRAM_H
#define FLAPPYGL_PROGRAM_H

#include <GL/glew.h>
#include "shader.h"

class Program {
private:
    GLuint program;
    // The default shaders to use, if another is not specified for a Shape
    Shader *defaultVertexShader;
    Shader *defaultFragmentShader;
public:
    Program(GLuint program);

    GLuint getID();

    GLint getUniform(const char *name);

    void use();
    void del();

    void attachShader(Shader *shader);
    void detachShader(Shader *shader);

    Shader *getDefaultVertexShader();
    void setDefaultVertexShader(Shader *vertexShader);

    Shader *getDefaultFragmentShader();
    void setDefaultFragmentShader(Shader *fragmentShader);

    void link();
};

Program createProgram();

#endif
