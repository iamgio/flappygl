#ifndef FLAPPYGL_BIRD_H
#define FLAPPYGL_BIRD_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define BIRD_SIZE 5
#define BIRD_X 20
#define BIRD_Y 40

class Bird: public GameObject {
public:
    Bird(): GameObject(BIRD_X, BIRD_Y, new BoundingBox(BIRD_SIZE, BIRD_SIZE)) {

    }

    Shape createShape(Scene *scene) {
        return createBirdShape();
    }

    void update();
};


#endif
