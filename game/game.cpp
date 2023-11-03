#include "game.h"

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
    this->scene->addShape(&shape);
}
