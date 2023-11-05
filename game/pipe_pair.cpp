#include <iostream>
#include "pipe_pair.h"
#include "../random.h"
#include "pipe.h"
#include "scoreincreaser.h"

// Minimum height between the hole and the sky/ground
#define SAFE_AREA_HEIGHT 10

std::tuple<GameObject*, GameObject*, GameObject*> createPipePair() {
    float groundPipeHeight = randomInt(SAFE_AREA_HEIGHT, SCENE_HEIGHT - SAFE_AREA_HEIGHT - HOLE_HEIGHT - GROUND_HEIGHT);
    float skyPipeHeight = SCENE_HEIGHT - groundPipeHeight - HOLE_HEIGHT - GROUND_HEIGHT;

    GameObject *ground = new Pipe(GROUND_PIPE, groundPipeHeight);
    GameObject *sky = new Pipe(SKY_PIPE, skyPipeHeight);

    GameObject *increaser = new ScoreIncreaser(groundPipeHeight + GROUND_HEIGHT);

    return std::make_tuple(ground, increaser, sky);
}

