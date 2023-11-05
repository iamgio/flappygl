#ifndef FLAPPYGL_PIPE_PAIR_H
#define FLAPPYGL_PIPE_PAIR_H

#include "gameobject.h"

// Ground pipe, score increaser, sky pipe
std::tuple<GameObject*, GameObject*, GameObject*> createPipePair();

#endif
