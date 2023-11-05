#ifndef FLAPPYGL_GAMEOBJECT_H
#define FLAPPYGL_GAMEOBJECT_H


#include "../collision/boundingbox.h"
#include "../shape.h"
#include "../scene/scene.h"

class GameObject {
private:
    int type;
    BoundingBox *boundingBox;
    int shapeIndex; // Index of the shape within the scene
protected:
    float x;
    float y;
    float rotation;
    glm::vec3 velocity;
public:
    GameObject(int type, float x, float y, BoundingBox *boundingBox);
    int getType();

    float getX();
    void setX(float newX);

    float getY();
    void setY(float y);

    float getRotation(); // In degrees
    void setRotation(float rotation);

    glm::vec3 getVelocity();
    void setVelocity(glm::vec3 velocity);

    BoundingBox *getBoundingBox();

    bool isColliding(GameObject *other);

    int getShapeIndex();
    void setShapeIndex(int index);

    virtual Shape createShape(Scene *scene) = 0;

    virtual void update() = 0;
};


#endif
