#ifndef FLAPPYGL_GROUND_H
#define FLAPPYGL_GROUND_H

#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define PROGRAM_GROUND_FRAGMENT_SHADER 0x0003

#define TYPE_GROUND 1
#define GROUND_WIDTH 1000
#define GROUND_HEIGHT 10

class Ground: public GameObject {
public:
    Ground(): GameObject(TYPE_GROUND, .0f, .0f, new BoundingBox(GROUND_WIDTH, GROUND_HEIGHT)) {

    }

    Shape createShape(Scene *scene) {
        Shape shape = createGroundShape();
        shape.fragmentShader = scene->getProgram()->getShader(PROGRAM_GROUND_FRAGMENT_SHADER);
        return shape;
    }

    void update() {

    }
};


#endif
