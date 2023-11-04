#include <iostream>
#include "pipe.h"

#define SPEED_X -0.3f

Pipe::Pipe(int type, float height): GameObject(TYPE_PIPE, SCENE_WIDTH, type ? GROUND_HEIGHT : SCENE_HEIGHT - height /*TODO when flipped*/, new BoundingBox(PIPE_WIDTH, height)) {
    this->type = type;
    this->height = height;
    this->velocity = glm::vec3(SPEED_X, .0f, .0f);

    if (type == SKY_PIPE) {
        // TODO fix collisions when flipped
        //this->x += PIPE_WIDTH;
        //this->rotation = 180; // Vertically flipped
    }
}

void Pipe::update() {

}