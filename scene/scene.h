#ifndef FLAPPYGL_SCENE_H
#define FLAPPYGL_SCENE_H


#include <vector>
#include "../shape.hpp"
#include "../settings.h"
#define GLT_IMPLEMENTATION
#include "../text/gltext.h"

// Scene height is fixed, scene width is calculated to maintain the aspect ratio
#define SCENE_HEIGHT 100
#define SCENE_WIDTH (SCENE_HEIGHT * ASPECT_RATIO)

class Scene {
private:
    GLuint vao;
    int shapeAmount;
    std::vector<Shape> shapes;
    GLint mvpUniformID;
public:
    Scene(GLuint vao, GLint mvpUniformID);
    void addShape(Shape shape);
    void removeShape(int index);
    void draw();
    int getShapesAmount();
    Shape *getShape(int index);
};


#endif
