#ifndef FLAPPYGL_BIRD_H
#define FLAPPYGL_BIRD_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"

class Bird: public GameObject {
public:
    Bird(): GameObject(80.0f, 80.0f, new BoundingBox(20, 20)) {

    }

    Shape createShape(Scene *scene) {
        return createBirdShape(scene);
    }

    void update();
};


#endif
