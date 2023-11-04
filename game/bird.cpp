#include "bird.h"

#define GRAVITY_Y -.015f

static glm::vec3 gravity = glm::vec3(.0f, GRAVITY_Y, .0f);

void Bird::update() {
    velocity += gravity;
}