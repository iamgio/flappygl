#include "bird.h"

#define BBOX_SIZE_FACTOR 1.2

#define GRAVITY_Y -.015f
#define JUMP_Y .45f

#define ROTATION_FACTOR 80
#define MIN_ROTATION -90

static glm::vec3 gravityForce = glm::vec3(.0f, GRAVITY_Y, .0f);
static glm::vec3 jumpForce = glm::vec3(.0f, JUMP_Y, .0f);

Bird::Bird(): GameObject(TYPE_BIRD, BIRD_X, BIRD_Y, new BoundingBox(BIRD_SIZE * BBOX_SIZE_FACTOR, BIRD_SIZE * BBOX_SIZE_FACTOR, true, true)) {

}

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
