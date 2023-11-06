#ifndef FLAPPYGL_SHADERS_H
#define FLAPPYGL_SHADERS_H

#include <GL/glew.h>

class Shaders {
private:
    GLuint program;
public:
    Shaders(GLuint program);
    GLint getUniform(const char *name);
    void use();
    void del();
};

Shaders loadShaders(const char *vertex_file_path, const char *fragment_file_path);

#endif