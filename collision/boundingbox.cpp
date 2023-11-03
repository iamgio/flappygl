#include <algorithm>
#include "boundingbox.h"

BoundingBox::BoundingBox(float width, float height) {
    this->width = width;
    this->height = height;
}

float BoundingBox::getWidth() {
    return this->width;
}

float BoundingBox::getHeight() {
    return this->height;
}

bool BoundingBox::isColliding(float x1, float y1, float x2, float y2, BoundingBox *other) {
    return std::max(x1, x2) < std::min(x1 + this->width, x2 + other->width)
                  && std::max(y1, y2) < std::min(y1 + this->height, y2 + other->height);
}
