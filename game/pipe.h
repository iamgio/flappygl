#ifndef FLAPPYGL_PIPE_H
#define FLAPPYGL_PIPE_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"
#include "ground.h"

#define TYPE_PIPE 2

#define PIPE_WIDTH 10

#define SKY_PIPE 0
#define GROUND_PIPE 1

class Pipe: public GameObject {
private:
    int type;
    float height;
public:
    Pipe(int type, float height): GameObject(TYPE_PIPE, SCENE_WIDTH, type ? GROUND_HEIGHT : SCENE_HEIGHT, new BoundingBox(PIPE_WIDTH, height)) {
        this->type = type;
        this->height = height;
        if (type == SKY_PIPE) {
            this->x += PIPE_WIDTH;
            this->rotation = 180; // Vertically flipped
        }
    }

    Shape createShape(Scene *scene) {
        return createPipeShape(height);
    }

    void update();
};


#endif
