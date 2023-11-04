#include "gameobject.h"


GameObject::GameObject(float x, float y, BoundingBox *boundingBox) {
    this->x = x;
    this->y = y;
    this->rotation = 0;
    this->boundingBox = boundingBox;
}

float GameObject::getX() {
    return this->x;
}

float GameObject::getY() {
    return this->y;
}

float GameObject::getRotation() {
    return this->rotation;
}

BoundingBox *GameObject::getBoundingBox() {
    return this->boundingBox;
}

bool GameObject::isColliding(GameObject *other) {
    return boundingBox->isColliding(x, y, other->getX(), other->getY(), other->getBoundingBox());
}

int GameObject::getShapeIndex() {
    return this->shapeIndex;
}

void GameObject::setShapeIndex(int index) {
    this->shapeIndex = index;
}
