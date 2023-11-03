#ifndef FLAPPYGL_GROUND_H
#define FLAPPYGL_GROUND_H

#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define GROUND_HEIGHT 60

class Ground: public GameObject {
public:
    Ground(): GameObject(.0f, .0f, new BoundingBox(1000, GROUND_HEIGHT)) {

    }

    Shape createShape(Scene *scene) {
        return createGroundShape(scene);
    }
};


#endif
