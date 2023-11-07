#ifndef FLAPPYGL_SHADER_H
#define FLAPPYGL_SHADER_H

#include <GL/glew.h>

class Shader {
private:
    GLuint shader;
    GLenum type;
public:
    Shader(GLuint shader, GLenum type);

    GLuint getID();
    GLenum getType();

    void del();
};

Shader loadShader(const char *path, GLenum type);

#endif