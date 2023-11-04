#include <iostream>
#include <queue>
#include "game.h"
#include "../scene/bbox.h"
#include "../settings.h"
#include "pipe_pair.h"
#include "bird.h"

#define PIPE_SPAWN_TICKS 700

// Internal timer
static int ticks = 0;

static std::queue<GameObject*> toAddQueue;

Game::Game(Scene *scene) {
    this->score = 0;
    this->objects = std::vector<GameObject*>();
    this->scene = scene;
}

void Game::addDequeuedObject() {
    // Dequeue of the first object to be added

    GameObject *object = toAddQueue.front();
    toAddQueue.pop();

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

void Game::addObject(GameObject *object) {
    toAddQueue.push(object);
}

void Game::start() {
    ticks = 0;
    srand(time(NULL));
}

void Game::handleCollisions(GameObject *object) {
    if (object->getType() != TYPE_BIRD) return;
    for (GameObject *other: objects) {
        if (object == other) continue;
        if (object->isColliding(other)) {
            std::cout << "BIRD COLLISION" << std::endl;
        }
    }
}

void Game::update() {
    // Objects are added here to avoid flickering
    if (!toAddQueue.empty()) {
        addDequeuedObject();
    }

    for (GameObject *object: objects) {
        object->setX(object->getX() + object->getVelocity().x);
        object->setY(object->getY() + object->getVelocity().y);

        object->update();
        handleCollisions(object);

        int index = object->getShapeIndex();
        Shape *shape = scene->getShape(index);
        shape->translation.x = object->getX();
        shape->translation.y = object->getY();
        shape->rotationAngle = glm::radians(object->getRotation());
    }

    // Spawn pipes
    if (ticks % PIPE_SPAWN_TICKS == 0) {
        auto pair = createPipePair();
        addObject(pair.first);
        addObject(pair.second);
    }

    ticks++;
}