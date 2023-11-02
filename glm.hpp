#ifndef FLAPPYGL_GLM_H
#define FLAPPYGL_GLM_H

#include <glm/glm.hpp>

bool isVecEmpty(glm::vec3 vec) {
    return !(vec.x || vec.y || vec.z);
}

#endif
