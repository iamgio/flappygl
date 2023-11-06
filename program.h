#ifndef FLAPPYGL_PROGRAM_H
#define FLAPPYGL_PROGRAM_H

#include <GL/glew.h>
#include <map>
#include "shader.h"

// The keys of the default shaders to use, if another is not specified for a Shape
#define PROGRAM_DEFAULT_VERTEX_SHADER 0x0001
#define PROGRAM_DEFAULT_FRAGMENT_SHADER 0x0002

typedef std::map<int, Shader*> ShaderMap;

class Program {
private:
    GLuint program;
    ShaderMap shaders;
public:
    Program(GLuint program);

    GLuint getID();

    GLint getUniform(const char *name);

    void use();
    void del();

    void attachShader(Shader *shader);
    void detachShader(Shader *shader);

    Shader *getShader(int key);
    void setShader(int key, Shader *shader);

    void link();
    void init(Shader *vertexShader, Shader *fragmentShader); // Attaches, links, detaches
};

Program createProgram();

#endif
