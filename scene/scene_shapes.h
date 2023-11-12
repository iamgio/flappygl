#ifndef FLAPPYGL_SCENE_SHAPES_H
#define FLAPPYGL_SCENE_SHAPES_H

#include "shape.h"
#include "scene.h"

Shape createBackgroundDetailsShape();
Shape createBirdShape();
Shape createGroundShape();
Shape createPipeShape(int type, float height);

#endif
