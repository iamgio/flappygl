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

// The default shaders to use, if another is not specified for a Shape
// extern Shader *defaultShaders;

Shader loadShader(const char *path, GLenum type);

#endif