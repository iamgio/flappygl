#ifndef FLAPPYGL_BIRD_H
#define FLAPPYGL_BIRD_H


#include "gameobject.h"
#include "../scene/scene_shapes.h"

#define PROGRAM_BIRD 5

#define TYPE_BIRD 0
#define BIRD_SIZE 5
#define BIRD_X 20
#define BIRD_Y 40

class Bird: public GameObject {
public:
    Bird();

    Shape createShape(Scene *scene) {
        Shape shape = createBirdShape();
        shape.shaderProgram = scene->getPrograms()->getProgram(PROGRAM_BIRD);
        return shape;
    }

    void update();

    void jump();
};


#endif
