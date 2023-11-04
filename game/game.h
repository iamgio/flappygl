#ifndef FLAPPYGL_GAME_H
#define FLAPPYGL_GAME_H

#include "../scene/scene.h"
#include "gameobject.h"

class Game {
private:
    int score;
    int ticks; // Internal timer
    std::vector<GameObject*> objects;
    Scene *scene;

    void addDequeuedObject();
    void removeDequeuedObject();
    void handleCollisions(GameObject *object);
public:
    Game(Scene *scene);
    void addObject(GameObject *object);
    void removeObject(GameObject *object);

    void start();
    void update();

    void jump();
};

#endif
