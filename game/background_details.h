#ifndef FLAPPYGL_BACKGROUND_DETAILS_H
#define FLAPPYGL_BACKGROUND_DETAILS_H

#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define TYPE_BACKGROUND_DETAILS 10

#define BACKGROUND_WIDTH SCENE_WIDTH
#define BACKGROUND_HEIGHT SCENE_HEIGHT

class BackgroundDetails: public GameObject {
public:
    BackgroundDetails(): GameObject(TYPE_BACKGROUND_DETAILS, .0f, .0f, new BoundingBox(0, 0)) {

    }

    Shape createShape(Scene *scene) {
        return createBackgroundDetailsShape();
    }

    void update() {

    }
};

#endif
