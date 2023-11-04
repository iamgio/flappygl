#ifndef FLAPPYGL_PIPE_H
#define FLAPPYGL_PIPE_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"
#include "ground.h"

#define PIPE_WIDTH 10
#define PIPE_HEIGHT 20 // TODO both 'up' and 'down' pipes should form a fixed-size hole

#define SKY_PIPE 0
#define GROUND_PIPE 1

class Pipe: public GameObject {
private:
    int type;
    float height;
public:
    Pipe(int type, float height): GameObject(SCENE_WIDTH, type ? GROUND_HEIGHT : SCENE_HEIGHT - height, new BoundingBox(PIPE_WIDTH, height)) {
        this->type = type;
        this->height = height;
    }

    Shape createShape(Scene *scene) {
        return createPipeShape(height);
    }

    void update();
};


#endif
