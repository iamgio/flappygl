#ifndef FLAPPYGL_HERMITE_H
#define FLAPPYGL_HERMITE_H

#include <vector>
#include <glm/glm.hpp>

#define PHI0(t)  (2.0*t*t*t-3.0*t*t+1)
#define PHI1(t)  (t*t*t-2.0*t*t+t)
#define PSI0(t)  (-2.0*t*t*t+3.0*t*t)
#define PSI1(t)  (t*t*t-t*t)

std::vector<glm::vec3> hermite(float p0x, float p0y, float p1x, float p1y, float v0x, float v0y, float v1x, float v1y) {
    std::vector<glm::vec3> points;

    for (float t = 0; t < 1; t += 0.01f) {
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

#endif
