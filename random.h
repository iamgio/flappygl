#ifndef FLAPPYGL_RANDOM_H
#define FLAPPYGL_RANDOM_H

#include <random>

int randomInt(int start, int end) {
    std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    std::uniform_int_distribution<> distr(start, end); // define the range

    return distr(gen);
}

#endif
