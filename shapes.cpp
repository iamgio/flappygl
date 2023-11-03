#include <iostream>
#include "shapes.hpp"
#include "shape.hpp"

static Shape generateRotation(float cx, float cy, int numTriangles, float *data, float (&x)(float theta, float*), float (&y)(float theta, float*)) {
    Shape shape = Shape {};

    int numVertices = numTriangles + 2; // vertici + vertice doppione inizio/fine + centro

    shape.verticesAmount = numVertices;
    shape.trianglesAmount = numTriangles;
    shape.method = GL_TRIANGLE_FAN;

    float step = 2 * PI / numTriangles; // angolo interno

    shape.vertices.push_back(glm::vec3(cx, cy, 0));
    shape.colors.push_back(glm::vec3(1, 0, 0));

    for (int i = 0; i <= numTriangles; i++) {
        float theta = i * step;

        float vx = cx + x(theta, data);
        float vy = cy + y(theta, data);

        shape.vertices.push_back(glm::vec3(vx, vy, 0));
        shape.colors.push_back(glm::vec3(1, 0, 0));
    }

    return shape;
}

static float circleX(float theta, float *data) {
    return data[0] * cos(theta);
}

static float circleY(float theta, float *data) {
    return data[1] * sin(theta);
}

Shape generateCircle(float cx, float cy, float rx, float ry, int numTriangles) {
    float *data = new float[] {rx, ry};
    return generateRotation(cx, cy, numTriangles, data, circleX, circleY);
}

static float heartX(float theta, float *data) {
    return 16 * sin(theta) * sin(theta) * sin(theta) / 30;
}

static float heartY(float theta, float *data) {
    return (13 * cos(theta) - 5 * cos(2 * theta) - 2 * cos(3 * theta) - cos(4 * theta)) / 30;
}

Shape generateHeart(float cx, float cy, int numTriangles) {
    return generateRotation(cx, cy, numTriangles, nullptr, heartX, heartY);
}

static float moonX(float theta, float *data) {
    return 3 * sin(theta) / 4;
}

static float moonY(float theta, float *data) {
    return (.5 - cos(2 * theta) - cos(theta)) / 4;
}

Shape generateMoon(float cx, float cy, int numTriangles) {
    return generateRotation(cx, cy, numTriangles, nullptr, moonX, moonY);
}