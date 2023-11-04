#ifndef FLAPPYGL_PIPE_H
#define FLAPPYGL_PIPE_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"
#include "ground.h"

#define PIPE_WIDTH 10
#define PIPE_HEIGHT 20 // TODO both 'up' and 'down' pipes should form a fixed-size hole

class Pipe: public GameObject {
public:
    Pipe(): GameObject(100.0f, GROUND_HEIGHT, new BoundingBox(PIPE_WIDTH, PIPE_HEIGHT)) {

    }

    Shape createShape(Scene *scene) {
        return createPipeShape();
    }

    void update();
};


#endif
