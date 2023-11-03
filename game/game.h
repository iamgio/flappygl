#ifndef FLAPPYGL_GAME_H
#define FLAPPYGL_GAME_H

#include "../scene/scene.h"
#include "gameobject.h"

class Game {
private:
    int score;
    std::vector<GameObject*> objects;
    Scene *scene;
public:
    Game(Scene *scene);
    std::vector<GameObject*> getGameObjects();
    void addObject(GameObject *object);
};

#endif
