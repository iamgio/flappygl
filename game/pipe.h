#ifndef FLAPPYGL_PIPE_H
#define FLAPPYGL_PIPE_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"
#include "ground.h"

#define PIPE_WIDTH 50
#define PIPE_HEIGHT 200

class Pipe: public GameObject {
public:
    Pipe(): GameObject(500.0f, GROUND_HEIGHT, new BoundingBox(PIPE_WIDTH, PIPE_HEIGHT)) {

    }

    Shape createShape(Scene *scene) {
        return createPipeShape(scene);
    }

    void update();
};


#endif
