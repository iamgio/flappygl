#include <algorithm>
#include "boundingbox.h"

BoundingBox::BoundingBox(float width, float height, bool centerX, bool centerY) {
    this->width = width;
    this->height = height;
    this->centerX = centerX;
    this->centerY = centerY;
}

BoundingBox::BoundingBox(float width, float height) : BoundingBox(width, height, false, false) {}

float BoundingBox::getWidth() {
    return this->width;
}

float BoundingBox::getHeight() {
    return this->height;
}

bool BoundingBox::isColliding(float x1, float y1, float x2, float y2, BoundingBox *other) {
    if (this->centerX) x1 -= width / 2;
    if (this->centerY) y1 -= height / 2;
    if (other->centerX) x2 -= other->width / 2;
    if (other->centerY) y2 -= other->height / 2;

    return std::max(x1, x2) < std::min(x1 + this->width, x2 + other->width)
                  && std::max(y1, y2) < std::min(y1 + this->height, y2 + other->height);
}
