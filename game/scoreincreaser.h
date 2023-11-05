#ifndef FLAPPYGL_SCOREINCREASER_H
#define FLAPPYGL_SCOREINCREASER_H


#include "gameobject.h"
#include "pipe.h"
#include "../shapes.h"

#define TYPE_SCORE_INCREASER 3

// Height of the zone between the pipes
#define HOLE_HEIGHT 16

class ScoreIncreaser: public GameObject {
public:
    ScoreIncreaser(float y): GameObject(TYPE_SCORE_INCREASER, PIPE_START_X, y, new BoundingBox(1, HOLE_HEIGHT)) {
        this->velocity = glm::vec3(PIPE_SPEED_X, .0f, .0f);
    }

    Shape createShape(Scene *scene) {
        return {};
    }

    void update() {

    }
};

#endif
