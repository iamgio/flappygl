#include <iostream>
#include "pipe_pair.h"
#include "../random.h"
#include "pipe.h"

// Height of the zone between the pipes
#define HOLE_HEIGHT 16
// Minimum height between the hole and the sky/ground
#define SAFE_AREA_HEIGHT 10

std::pair<GameObject*, GameObject*> createPipePair() {
    float groundPipeHeight = randomInt(SAFE_AREA_HEIGHT, SCENE_HEIGHT - SAFE_AREA_HEIGHT - HOLE_HEIGHT - GROUND_HEIGHT);
    float skyPipeHeight = SCENE_HEIGHT - groundPipeHeight - HOLE_HEIGHT - GROUND_HEIGHT;

    GameObject *ground = new Pipe(GROUND_PIPE, groundPipeHeight);
    GameObject *sky = new Pipe(SKY_PIPE, skyPipeHeight);

    return std::make_pair(ground, sky);
}

