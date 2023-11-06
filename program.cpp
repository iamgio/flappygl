#include <iostream>
#include "program.h"

Program::Program(GLuint program) {
    this->program = program;
}

GLuint Program::getID() {
    return this->program;
}

GLint Program::getUniform(const char *name) {
    return glGetUniformLocation(this->program, name);
}

void Program::use() {
    glUseProgram(this->program);
}

void Program::del() {
    glDeleteProgram(this->program);
}

void Program::attachShader(Shader *shader) {
    glAttachShader(this->program, shader->getID());
}

void Program::detachShader(Shader *shader) {
    glDetachShader(this->program, shader->getID());
}

Shader *Program::getDefaultVertexShader() {
    return this->defaultVertexShader;
}

void Program::setDefaultVertexShader(Shader *vertexShader) {
    this->defaultVertexShader = vertexShader;
}

Shader *Program::getDefaultFragmentShader() {
    return this->defaultFragmentShader;
}

void Program::setDefaultFragmentShader(Shader *fragmentShader) {
    this->defaultFragmentShader = fragmentShader;
}

void Program::link() {
    GLint Result = GL_FALSE;
    int InfoLogLength;

    glLinkProgram(this->program);

    // Check the program
    glGetProgramiv(this->program, GL_LINK_STATUS, &Result);
    glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(this->program, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    /*glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);*/
}

Program createProgram() {
    return glCreateProgram();
}
