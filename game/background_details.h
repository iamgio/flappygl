#ifndef FLAPPYGL_BACKGROUND_DETAILS_H
#define FLAPPYGL_BACKGROUND_DETAILS_H

#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define PROGRAM_BACKGROUND 4

#define TYPE_BACKGROUND_DETAILS 10

class BackgroundDetails: public GameObject {
public:
    BackgroundDetails(): GameObject(TYPE_BACKGROUND_DETAILS, .0f, .0f, new BoundingBox(0, 0)) {

    }

    Shape createShape(Scene *scene) {
        Shape shape = createBackgroundDetailsShape();
        shape.shaderProgram = scene->getPrograms()->getProgram(PROGRAM_BACKGROUND);
        return shape;
    }

    void update() {

    }
};

#endif
