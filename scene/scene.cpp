#include <glm/gtc/matrix_transform.hpp>
#include "scene.h"
#include "../gl.hpp"
#include "../shapes.hpp"
#include "../mvp.h"

#define BACKGROUND_COLOR 0.58f, 0.91f, 0.96f

// Orthographic projection
static glm::mat4 projection;

Scene::Scene(float width, float height, GLint mvpUniformID) {
    this->mvpUniformID = mvpUniformID;
    // [-1,1] -> [0,SIZE] mapping
    projection = glm::ortho(0.0f, width, height, 0.0f);

    this->shapes = std::vector<Shape>();

    // test

    const int numTriangles = 50;

    Shape shape = generateCircle(.0f, .0f, .5f, .5f, numTriangles);

    shape.translation = glm::vec3(50.0f, 50.0f, 0.0f);
    shape.scale = glm::vec3(100.0f, 100.0f, 1.0f);

    // Set up Vertex Buffer
    shape.verticesVbo = newBuffer(&shape.vertices.front(), shape.vertices.size() * sizeof(glm::vec3) * sizeof(GLfloat));
    // Set up Color Buffer
    shape.colorsVbo = newBuffer(&shape.colors.front(), shape.colors.size() * sizeof(glm::vec3) * sizeof(GLfloat));

    this->shapes.push_back(shape);

    // test end

    backgroundColor(BACKGROUND_COLOR);
}

std::vector<Shape> Scene::getShapes() {
    return this->shapes;
}

void Scene::draw() {
    for (Shape shape : this->shapes) {
        glm::mat4 mvp = getMVPMatrix(&shape, projection);
        updateMVP(mvp, this->mvpUniformID);
        ::draw(shape.verticesVbo, shape.colorsVbo, shape.verticesAmount);
    }
}
