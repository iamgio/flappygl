#ifndef FLAPPYGL_PIPE_H
#define FLAPPYGL_PIPE_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"
#include "ground.h"

#define TYPE_PIPE 2

#define PIPE_WIDTH 10

#define SKY_PIPE 0
#define GROUND_PIPE 1

#define PIPE_START_X (SCENE_WIDTH + PIPE_WIDTH)
#define PIPE_SPEED_X -0.3f

class Pipe: public GameObject {
private:
    int type;
    float height;
public:
    Pipe(int type, float height);

    Shape createShape(Scene *scene) {
        return createPipeShape(type, height);
    }

    void update();
};


#endif
