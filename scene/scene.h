#ifndef FLAPPYGL_SCENE_H
#define FLAPPYGL_SCENE_H


#include <vector>
#include "../shape.hpp"
#include "../settings.h"

// Scene height is fixed, scene width is calculated to maintain the aspect ratio
#define SCENE_HEIGHT 100
#define SCENE_WIDTH (SCENE_HEIGHT * ASPECT_RATIO)

class Scene {
private:
    int shapeAmount;
    std::vector<Shape> shapes;
    GLint mvpUniformID;
public:
    Scene(GLint mvpUniformID);
    void addShape(Shape shape);
    void removeShape(int index);
    void draw();
    int getShapesAmount();
    Shape *getShape(int index);
};


#endif
