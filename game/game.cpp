#include <iostream>
#include <queue>
#include "game.h"
#include "../settings.h"
#include "pipe_pair.h"
#include "bird.h"
#include "ground.h"
#include "scoreincreaser.h"

// Time after game end to start a new game
#define RESTART_TICKS 80

#define PIPE_SPAWN_TICKS 180

// When going past this X coordinate, an object is removed
#define REMOVE_OBJECTS_X_THRESHOLD -50

static std::queue<GameObject*> toAddQueue;
static std::queue<GameObject*> toRemoveQueue;

// Ticks when the game ended
static int endGameTicks;

Game::Game(Scene *scene) {
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

void Game::removeDequeuedObject() {
    // Dequeue of the first object to be removed

    GameObject *object = toRemoveQueue.front();
    toRemoveQueue.pop();

    this->scene->removeShape(object->getShapeIndex());
    this->objects.erase(std::remove(objects.begin(), objects.end(), object), objects.end());
}

void Game::addObject(GameObject *object) {
    toAddQueue.push(object);
}

void Game::removeObject(GameObject *object) {
    toRemoveQueue.push(object);
}

void Game::start() {
    score = 0;
    ticks = 0;
    endGameTicks = 0;
    shouldUpdate = true;

    this->objects = std::vector<GameObject*>();

    srand(time(NULL));

    this->addObject(new Ground());
    this->addObject(new Bird());
}

void Game::handleCollisions(GameObject *object) {
    if (object->getType() != TYPE_BIRD) return;
    for (GameObject *other: objects) {
        if (object == other || !object->isColliding(other)) continue;

        if (other->getType() == TYPE_SCORE_INCREASER) {
            score++;
            removeObject(other);
            std::cout << "Score " << score << std::endl;
        } else {
            std::cout << "BIRD COLLISION" << std::endl;
            stop();
        }
    }
}

void Game::update() {
    ticks++;

    if (!shouldUpdate) {
        if (ticks - endGameTicks > RESTART_TICKS) {
            restart();
        }
        return;
    }

    // Objects are added here to avoid flickering
    if (!toAddQueue.empty()) {
        addDequeuedObject();
    }
    if (!toRemoveQueue.empty()) {
        removeDequeuedObject();
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

        if (object->getX() < REMOVE_OBJECTS_X_THRESHOLD) {
            removeObject(object);
        }
    }

    // Spawn pipes
    if (ticks % PIPE_SPAWN_TICKS == 0) {
        auto pair = createPipePair();
        addObject(std::get<0>(pair));
        addObject(std::get<1>(pair));
        addObject(std::get<2>(pair));
    }
}

void Game::stop() {
    shouldUpdate = false;
    endGameTicks = ticks;
}

void Game::restart() {
    while (!toAddQueue.empty()) toAddQueue.pop();

    for (GameObject *object: objects) {
        removeObject(object);
    }

    start();
}

void Game::jump() {
    for (GameObject *object: objects) {
        if (object->getType() != TYPE_BIRD) continue;

        ((Bird*) object)->jump();
    }
}