#include <iostream>
#include "pipe.h"
#include "game.h"

Pipe::Pipe(int type, float height): GameObject(TYPE_PIPE,
        PIPE_START_X,
        type ? GROUND_HEIGHT : SCENE_HEIGHT - height,
        new BoundingBox(PIPE_WIDTH, height, true, false)) {

    this->type = type;
    this->height = height;
    this->velocity = glm::vec3(PIPE_SPEED_X, .0f, .0f);
}

void Pipe::update() {

}