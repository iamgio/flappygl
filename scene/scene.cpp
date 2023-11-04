#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
#include "scene.h"
#include "scene_shapes.h"
#include "../gl.hpp"
#include "../shapes.hpp"
#include "../mvp.h"

#define BACKGROUND_COLOR 0.58f, 0.91f, 0.96f

// Orthographic projection
static glm::mat4 projection;

Scene::Scene(float width, float height, GLint mvpUniformID) {
    this->width = width;
    this->height = height;
    this->shapeAmount = 0;
    this->mvpUniformID = mvpUniformID;
    // [-1,1] -> [0,SIZE] mapping
    // Y=0 is on the bottom for better usability
    projection = glm::ortho(0.0f, width, 0.0f, height);

    this->shapes = std::array<Shape, MAX_SHAPES>();

    backgroundColor(BACKGROUND_COLOR);
}

void Scene::addShape(Shape shape) {
    const auto vecSize = sizeof(glm::vec3) * sizeof(GLfloat);
    if (!shape.verticesVbo) {
        // Set up Vertex Buffer
        shape.verticesVbo = newBuffer(&shape.vertices.front(), shape.vertices.size() * vecSize);
    }

    if (!shape.colorsVbo) {
        // Set up Color Buffer
        shape.colorsVbo = newBuffer(&shape.colors.front(), shape.colors.size() * vecSize);
    }

    this->shapes[shapeAmount++] = shape;
}

void Scene::draw() {
    for (Shape shape : this->shapes) {
        glm::mat4 mvp = getMVPMatrix(&shape, projection);
        updateMVP(mvp, this->mvpUniformID);
        ::draw(shape.verticesVbo, shape.colorsVbo, shape.verticesAmount, shape.method);
    }
}

float Scene::getWidth() {
    return this->width;
}

float Scene::getHeight() {
    return this->height;
}

int Scene::getShapesAmount() {
    return this->shapeAmount;
}

Shape *Scene::getShape(int index) {
    return &this->shapes[index];
}
