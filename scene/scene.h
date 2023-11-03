#ifndef FLAPPYGL_SCENE_H
#define FLAPPYGL_SCENE_H


#include <vector>
#include "../shape.hpp"

class Scene {
private:
    float width;
    float height;
    std::vector<Shape> shapes;
    GLint mvpUniformID;
public:
    Scene(float width, float height, GLint mvpUniformID);
    void addShape(Shape *shape);
    void draw();
    float getWidth();
    float getHeight();
};


#endif
