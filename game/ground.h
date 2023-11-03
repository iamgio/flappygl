#ifndef FLAPPYGL_GROUND_H
#define FLAPPYGL_GROUND_H

#include "gameobject.h"
#include "../scene/scene_shapes.h"

class Ground: public GameObject {
public:
    // TODO values
    Ground(): GameObject(0.0f, 20.0f, new BoundingBox(100.0f, 20.0f)) {

    }

    Shape createShape(Scene *scene) {
        return createGroundShape(scene);
    }
};


#endif
