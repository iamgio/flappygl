#ifndef FLAPPYGL_SCENE_H
#define FLAPPYGL_SCENE_H


#include <vector>
#include "../shape.h"
#include "../settings.h"
#define GLT_IMPLEMENTATION
#include "../lib/gltext.h"
#include "../program.h"
#include "../programs.h"

// Scene height is fixed, scene width is calculated to maintain the aspect ratio
#define SCENE_HEIGHT 100
#define SCENE_WIDTH (SCENE_HEIGHT * ASPECT_RATIO)

class Scene {
private:
    Programs *programs;
    GLuint vao;
    int shapeAmount;
    std::vector<Shape> shapes;
    GLint mvpUniformID;
public:
    Scene(Programs *programs, GLuint vao, GLint mvpUniformID);

    Programs *getPrograms();

    void addShape(Shape shape);
    void removeShape(int index);

    void draw();

    int getShapesAmount();
    Shape *getShape(int index);
};


#endif
