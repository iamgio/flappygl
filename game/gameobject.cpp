#include "gameobject.h"


GameObject::GameObject(int type, float x, float y, BoundingBox *boundingBox) {
    this->type = type;
    this->x = x;
    this->y = y;
    this->rotation = 0;
    this->boundingBox = boundingBox;
}

int GameObject::getType() {
    return this->type;
}

float GameObject::getX() {
    return this->x;
}

void GameObject::setX(float newX) {
    this->x = newX;
}

float GameObject::getY() {
    return this->y;
}

void GameObject::setY(float newY) {
    this->y = newY;
}

float GameObject::getRotation() {
    return this->rotation;
}

void GameObject::setRotation(float newRotation) {
    this->rotation = newRotation;
}

glm::vec3 GameObject::getVelocity() {
    return this->velocity;
}

void GameObject::setVelocity(glm::vec3 newVelocity) {
    this->velocity = newVelocity;
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