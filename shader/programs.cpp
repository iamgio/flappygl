#include "programs.h"

Program *Programs::getProgram(int key) {
    return programMap.at(key);
}

void Programs::setProgram(int key, Program *program) {
    programMap.insert(ProgramMap::value_type(key, program));
}