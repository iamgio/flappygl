#ifndef FLAPPYGL_SCENE_H
#define FLAPPYGL_SCENE_H


#include <vector>
#include "../shape.hpp"

class Scene {
private:
    std::vector<Shape> shapes;
    GLint mvpUniformID;
public:
    Scene(float width, float height, GLint mvpUniformID);
    std::vector<Shape> getShapes();
    void draw();
};


#endif
