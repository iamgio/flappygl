#include <iostream>
#include "game.h"
#include "../scene/bbox.h"
#include "../settings.h"

Game::Game(Scene *scene) {
    this->score = 0;
    this->objects = std::vector<GameObject*>();
    this->scene = scene;
}

std::vector<GameObject*> Game::getGameObjects() {
    return this->objects;
}

void Game::addObject(GameObject *object) {
    this->objects.push_back(object);
    Shape shape = object->createShape(this->scene);
    int index = scene->getShapesAmount();
    object->setShapeIndex(index);
    this->scene->addShape(shape);

#ifdef SHOW_BBOX
    Shape bbox = createBoundingBoxShape(object);
    this->scene->addShape(&bbox);
#endif
}

void Game::update() {
    for (GameObject *object: objects) {
        object->update();

        int index = object->getShapeIndex();
        Shape *shape = scene->getShape(index);
        shape->translation.x = object->getX();
        shape->translation.y = object->getY();
    }
}