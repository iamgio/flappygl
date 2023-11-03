#ifndef FLAPPYGL_BBOX_H
#define FLAPPYGL_BBOX_H

#include "../shape.hpp"
#include "../game/gameobject.h"

Shape createBoundingBoxShape(GameObject *object) {
    Shape bbox = Shape {
            .verticesAmount = 4,
            .method = GL_LINE_LOOP
    };
    bbox.vertices.push_back(glm::vec3(object->getX(), object->getY(), .0f));
    bbox.vertices.push_back(glm::vec3(object->getX() + object->getBoundingBox()->getWidth(), object->getY(), .0f));
    bbox.vertices.push_back(glm::vec3(object->getX() + object->getBoundingBox()->getWidth(), object->getY() + object->getBoundingBox()->getHeight(), .0f));
    bbox.vertices.push_back(glm::vec3(object->getX(), object->getY() + object->getBoundingBox()->getHeight(), .0f));

    for (int i = 0; i < 4; i++) {
        bbox.colors.push_back(glm::vec3(1, 1, 1));
    }

    return bbox;
}

#endif
