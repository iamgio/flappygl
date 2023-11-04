#ifndef FLAPPYGL_GROUND_H
#define FLAPPYGL_GROUND_H

#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define TYPE_GROUND 1
#define GROUND_WIDTH 1000
#define GROUND_HEIGHT 10

class Ground: public GameObject {
public:
    Ground(): GameObject(TYPE_GROUND, .0f, .0f, new BoundingBox(GROUND_WIDTH, GROUND_HEIGHT)) {

    }

    Shape createShape(Scene *scene) {
        return createGroundShape();
    }

    void update() {

    }
};


#endif
