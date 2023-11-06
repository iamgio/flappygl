#ifndef FLAPPYGL_SHADER_H
#define FLAPPYGL_SHADER_H

#include <GL/glew.h>

class Shader {
private:
    GLuint shader;
public:
    Shader(GLuint shader);

    GLuint getID();

    void del();
};

Shader loadShader(const char *path, GLenum type);

#endif