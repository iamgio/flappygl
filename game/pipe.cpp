#include <iostream>
#include "pipe.h"
#include "game.h"

#define SPEED_X -0.3f

Pipe::Pipe(int type, float height): GameObject(TYPE_PIPE,
        SCENE_WIDTH + PIPE_WIDTH,
        type ? GROUND_HEIGHT : SCENE_HEIGHT - height,
        new BoundingBox(PIPE_WIDTH, height, true, false)) {

    this->type = type;
    this->height = height;
    this->velocity = glm::vec3(SPEED_X, .0f, .0f);

    if (type == SKY_PIPE) {
        this->rotation = 180; // Vertically flipped
    }
}

void Pipe::update() {

}