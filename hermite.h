#ifndef FLAPPYGL_HERMITE_H
#define FLAPPYGL_HERMITE_H

#include <vector>
#include <glm/glm.hpp>

// Hermite curve between two points
std::vector<glm::vec3> hermite2(float p0x, float p0y,
                                float p1x, float p1y,
                                float v0x, float v0y,
                                float v1x, float v1y);

// Hermite curve between three points
std::vector<glm::vec3> hermite3(float p0x, float p0y,
                                float p1x, float p1y,
                                float p2x, float p2y,
                                float v0x, float v0y,
                                float v1x, float v1y,
                                float v2x, float v2y);

// Hermite curve between five points
std::vector<glm::vec3> hermite5(float p0x, float p0y,
                                float p1x, float p1y,
                                float p2x, float p2y,
                                float p3x, float p3y,
                                float p4x, float p4y,
                                float v0x, float v0y,
                                float v1x, float v1y,
                                float v2x, float v2y,
                                float v3x, float v3y,
                                float v4x, float v4y);

// Concatenates two vectors of coordinates and returns a copy
std::vector<glm::vec3> concatenate(std::vector<glm::vec3> v1, std::vector<glm::vec3> v2);

#endif