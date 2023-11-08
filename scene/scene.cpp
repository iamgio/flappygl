#include <glm/gtc/matrix_transform.hpp>
#include "scene.h"
#include "../gl.h"
#include "../shapes.h"
#include "../settings.h"
#include "../glm.h"

#define BACKGROUND_COLOR 0.58f, 0.91f, 0.96f

// Orthographic projection
static glm::mat4 projection;

Scene::Scene(Programs *programs, GLuint vao, GLint mvpUniformID) {
    this->programs = programs;
    this->vao = vao;
    this->shapeAmount = 0;
    this->mvpUniformID = mvpUniformID;
    // [-1,1] -> [0,SIZE] mapping
    // Y=0 is on the bottom for better usability
    projection = glm::ortho(.0f, (float) SCENE_WIDTH, .0f, (float) SCENE_HEIGHT);

    this->shapes = std::vector<Shape>();

    backgroundColor(BACKGROUND_COLOR);
}

Programs *Scene::getPrograms() {
    return this->programs;
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

    this->shapes.push_back(shape);
    shapeAmount++;
}

void Scene::removeShape(int index) {
    freeShape(this->shapes[index]);
    this->shapes[index] = {};
}

static Program *lastUsedProgram;

void Scene::draw() {
    for (Shape shape : this->shapes) {
        if (shape.vertices.empty()) continue;

        // Find the shader program to use
        Program *program = shape.shaderProgram ? shape.shaderProgram : programs->getProgram(PROGRAM_DEFAULT);
        if (!lastUsedProgram || program != lastUsedProgram) {
            program->use();
            lastUsedProgram = program;
        }

        // Get the MVP matrix
        glm::mat4 mvp = getMVPMatrix(&shape, projection);
        updateMVP(mvp, this->mvpUniformID);

        // Draw the shape
        ::draw(this->vao, shape.verticesVbo, shape.colorsVbo, shape.verticesAmount, shape.method);
    }
}

int Scene::getShapesAmount() {
    return this->shapeAmount;
}

Shape *Scene::getShape(int index) {
    return &this->shapes[index];
}
