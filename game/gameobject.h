#ifndef FLAPPYGL_GAMEOBJECT_H
#define FLAPPYGL_GAMEOBJECT_H


#include "../collision/boundingbox.h"
#include "../shape.hpp"
#include "../scene/scene.h"

class GameObject {
private:
    BoundingBox *boundingBox;
    int shapeIndex; // Index of the shape within the scene
protected:
    float x;
    float y;
    float rotation;
public:
    GameObject(float x, float y, BoundingBox *boundingBox);
    float getX();
    float getY();
    float getRotation(); // In degrees
    BoundingBox *getBoundingBox();

    bool isColliding(GameObject *other);

    int getShapeIndex();
    void setShapeIndex(int index);

    virtual Shape createShape(Scene *scene) = 0;

    virtual void update() = 0;
};


#endif
