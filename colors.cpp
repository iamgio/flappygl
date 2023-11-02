#include <GL/glew.h>
#include <vector>
#include <random>

std::vector<GLfloat> generateRandomColors(int n) {
    // Random set up
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_real_distribution<> dis(0, 1); // Uniform distribution between 0 and 1

    std::vector<GLfloat> colors(n * 3);

    for (int i = 0; i < n * 3; i++) {
        colors[i] = dis(gen);
    }
    return colors;
}