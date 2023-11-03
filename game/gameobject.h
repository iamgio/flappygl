#ifndef FLAPPYGL_GAMEOBJECT_H
#define FLAPPYGL_GAMEOBJECT_H


#include "../collision/boundingbox.h"
#include "../shape.hpp"
#include "../scene/scene.h"

class GameObject {
private:
    float x;
    float y;
    BoundingBox *boundingBox;
public:
    GameObject(float x, float y, BoundingBox *boundingBox);
    float getX();
    float getY();
    BoundingBox *getBoundingBox();

    bool isColliding(GameObject *other);

    virtual Shape createShape(Scene *scene) = 0;
};


#endif
