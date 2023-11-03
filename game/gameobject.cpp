#include "gameobject.h"


GameObject::GameObject(float x, float y, BoundingBox *boundingBox) {
    this->x = x;
    this->y = y;
    this->boundingBox = boundingBox;
}

float GameObject::getX() {
    return this->x;
}

float GameObject::getY() {
    return this->y;
}

BoundingBox *GameObject::getBoundingBox() {
    return this->boundingBox;
}

bool GameObject::isColliding(GameObject *other) {
    return boundingBox->isColliding(x, y, other->getX(), other->getY(), other->getBoundingBox());
}

Shape *GameObject::getShape() {
    return &this->shape;
}

void GameObject::setShape(Shape *shape) {
    this->shape = *shape;
}
