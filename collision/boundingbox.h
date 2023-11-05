#ifndef FLAPPYGL_BOUNDINGBOX_H
#define FLAPPYGL_BOUNDINGBOX_H


class BoundingBox {
private:
    float width;
    float height;
    bool centerX;
    bool centerY;
public:
    BoundingBox(float width, float height);
    BoundingBox(float width, float height, bool centerX, bool centerY);
    float getWidth();
    float getHeight();

    bool isColliding(float x1, float y1, float x2, float y2, BoundingBox *other);
};


#endif
