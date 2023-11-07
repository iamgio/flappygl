#include "hermite.h"

#define PHI0(t)  (2.0 * t * t * t - 3.0 * t * t + 1)
#define PHI1(t)  (t * t * t - 2.0 * t * t + t)
#define PSI0(t)  (-2.0 * t * t * t + 3.0 * t * t)
#define PSI1(t)  (t * t * t - t * t)

#define HERMITE_PRECISION 0.01f

std::vector<glm::vec3> hermite2(float p0x, float p0y, float p1x, float p1y,
                                float v0x, float v0y, float v1x, float v1y) {
    std::vector<glm::vec3> points;

    for (float t = 0; t < 1; t += HERMITE_PRECISION) {
        float phi0 = PHI0(t);
        float phi1 = PHI1(t);
        float psi0 = PSI0(t);
        float psi1 = PSI1(t);

        float px = p0x * phi0 + p1x * psi0 + v0x * phi1 + v1x * psi1;
        float py = p0y * phi0 + p1y * psi0 + v0y * phi1 + v1y * psi1;

        points.push_back(glm::vec3(px, py, 0));
    }

    return points;
}

std::vector<glm::vec3> concatenate(std::vector<glm::vec3> v1, std::vector<glm::vec3> v2) {
    auto v3 = std::vector<glm::vec3>(v1);
    v3.insert(v3.end(), v2.begin(), v2.end());
    return v3;
}

std::vector<glm::vec3> hermite3(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y,
                                float v0x, float v0y, float v1x, float v1y, float v2x, float v2y) {
    auto v1 = hermite2(p0x, p0y, p1x, p1y, v0x, v0y, v1x, v1y);
    auto v2 = hermite2(p1x, p1y, p2x, p2y, v1x, v1y, v2x, v2y);

    return concatenate(v1, v2);
}

std::vector<glm::vec3> hermite5(float p0x, float p0y, float p1x, float p1y, float p2x, float p2y, float p3x, float p3y, float p4x, float p4y,
                                float v0x, float v0y, float v1x, float v1y, float v2x, float v2y, float v3x, float v3y, float v4x, float v4y) {
    auto v1 = hermite3(p0x, p0y, p1x, p1y, p2x, p2y, v0x, v0y, v1x, v1y, v2x, v2y);
    auto v2 = hermite3(p2x, p2y, p3x, p3y, p4x, p4y, v2x, v2y, v3x, v3y, v4x, v4y);

    return concatenate(v1, v2);
}