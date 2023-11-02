#ifndef FLAPPYGL_MVP_H
#define FLAPPYGL_MVP_H

#include <glm/glm.hpp>
#include "shape.hpp"

glm::mat4 getMVPMatrix(Shape *shape, glm::mat4 projection);

#endif
