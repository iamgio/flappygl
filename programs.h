#ifndef FLAPPYGL_PROGRAMS_H
#define FLAPPYGL_PROGRAMS_H


#include <map>
#include "shader.h"
#include "program.h"

// The key of the default program to use, if another is not specified for a Shape
#define PROGRAM_DEFAULT 1

typedef std::map<int, Program*> ProgramMap;

class Programs {
private:
    ProgramMap programMap;
public:
    Program *getProgram(int key);
    void setProgram(int key, Program *program);
};


#endif
