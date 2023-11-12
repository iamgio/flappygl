#ifndef FLAPPYGL_GLM_H
#define FLAPPYGL_GLM_H

#include <glm/glm.hpp>
#include "scene/shape.h"

bool isVecEmpty(glm::vec3 vec);

glm::mat4 getMVPMatrix(Shape *shape, glm::mat4 projection);

#endif
