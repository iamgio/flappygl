#include <iostream>
#include "bird.h"

#define GRAVITY_Y -.015f
#define JUMP_Y .45f

#define ROTATION_FACTOR 80
#define MIN_ROTATION -90

static glm::vec3 gravityForce = glm::vec3(.0f, GRAVITY_Y, .0f);
static glm::vec3 jumpForce = glm::vec3(.0f, JUMP_Y, .0f);

void Bird::update() {
    velocity += gravityForce;

    // Slight rotation interpolation

    float rotationTarget = velocity.y * ROTATION_FACTOR;
    if (rotationTarget < MIN_ROTATION) rotationTarget = MIN_ROTATION;

    rotation = (rotation + rotationTarget) / 2;
}

void Bird::jump() {
    if (velocity.y < jumpForce.y / 4) {
        velocity = jumpForce;
    }
}
