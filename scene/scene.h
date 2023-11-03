#ifndef FLAPPYGL_SCENE_H
#define FLAPPYGL_SCENE_H


#include <vector>
#include "../shape.hpp"

#define MAX_SHAPES 100

class Scene {
private:
    float width;
    float height;
    int shapeAmount;
    std::array<Shape, MAX_SHAPES> shapes;
    GLint mvpUniformID;
public:
    Scene(float width, float height, GLint mvpUniformID);
    void addShape(Shape shape);
    void draw();
    float getWidth();
    float getHeight();
    int getShapesAmount();
    Shape *getShape(int index);
};


#endif
