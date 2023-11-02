#include <glm/gtc/matrix_transform.hpp>
#include "mvp.h"
#include "glm.hpp"

glm::mat4 getMVPMatrix(Shape *shape, glm::mat4 projection) {
    // Transformations
    glm::mat4 model = glm::mat4(1.0);

    if (!isVecEmpty(shape->translation)) {
        model = glm::translate(model, shape->translation);
    }
    if (!isVecEmpty(shape->scale)) {
        model = glm::scale(model, shape->scale);
    }

    return projection * model;
}