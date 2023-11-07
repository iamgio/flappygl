#ifndef FLAPPYGL_HERMITE_H
#define FLAPPYGL_HERMITE_H

#include <vector>
#include <glm/glm.hpp>

// Hermite curve between two points
std::vector<glm::vec3> hermite2(float p0x, float p0y, float p1x, float p1y, float v0x, float v0y, float v1x, float v1y);

// Hermite curve between three points
std::vector<glm::vec3> hermite3(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float v0x, float v0y, float v1x, float v1y, float v2x, float v2y);

#endif
