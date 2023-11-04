#include "bird.h"

#define GRAVITY_Y -.015f
#define JUMP_Y .45f

static glm::vec3 gravityForce = glm::vec3(.0f, GRAVITY_Y, .0f);
static glm::vec3 jumpForce = glm::vec3(.0f, JUMP_Y, .0f);

void Bird::update() {
    velocity += gravityForce;
}

void Bird::jump() {
    if (velocity.y < jumpForce.y / 4) {
        velocity = jumpForce;
    }
}
