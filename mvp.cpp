#include <glm/gtc/matrix_transform.hpp>
#include "mvp.h"
#include "glm.hpp"

glm::mat4 getMVPMatrix(Shape *shape, glm::mat4 projection) {
    // Transformations
    glm::mat4 model = glm::mat4(1.0);

    if (!isVecEmpty(shape->translation)) {
        model = glm::translate(model, shape->translation);
    }

    // For usability, rotations always happen along the Z axis in 2D
    glm::vec3 rotationAxis = glm::vec3(0, 0, 1);
    //if (!isVecEmpty(shape->rotationAxis)) {
    model = glm::rotate(model, shape->rotationAngle, /*shape->*/rotationAxis);

    if (!isVecEmpty(shape->scale)) {
        model = glm::scale(model, shape->scale);
    }

    return projection * model;
}