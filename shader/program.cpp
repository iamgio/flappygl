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

Shader *Program::getShader(int key) {
    return this->shaders.at(key);
}

void Program::setShader(int key, Shader *shader) {
    this->shaders.insert(ShaderMap::value_type(key, shader));
}

void Program::link() {
    glLinkProgram(this->program);

    /*
    GLint Result = GL_FALSE;
    int InfoLogLength;
    // Check the program
    glGetProgramiv(this->program, GL_LINK_STATUS, &Result);
    glGetProgramiv(this->program, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if (InfoLogLength > 0) {
        std::vector<char> ProgramErrorMessage(InfoLogLength + 1);
        glGetProgramInfoLog(this->program, InfoLogLength, nullptr, &ProgramErrorMessage[0]);
        printf("%s\n", &ProgramErrorMessage[0]);
    }

    glDetachShader(ProgramID, VertexShaderID);
    glDetachShader(ProgramID, FragmentShaderID);

    glDeleteShader(VertexShaderID);
    glDeleteShader(FragmentShaderID);*/
}

void Program::init(Shader *vertexShader, Shader *fragmentShader) {
    attachShader(vertexShader);
    attachShader(fragmentShader);

    link();

    detachShader(vertexShader);
    detachShader(fragmentShader);

    setShader(PROGRAM_DEFAULT_VERTEX_SHADER, vertexShader);
    setShader(PROGRAM_DEFAULT_FRAGMENT_SHADER, fragmentShader);
}

Program createProgram() {
    return glCreateProgram();
}

Program createProgram(Shader *vertexShader, Shader *fragmentShader) {
    Program program = createProgram();
    program.init(vertexShader, fragmentShader);
    return program;
}
