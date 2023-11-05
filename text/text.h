#ifndef FLAPPYGL_TEXT_H
#define FLAPPYGL_TEXT_H

#define GLT_IMPLEMENTATION
#include "../lib/gltext.h"

class Text {
private:

public:
    GLTtext *text;
    Text();

    void setColor(float r, float g, float b);
    void setText(const char *string);
    void draw(float x, float y, float scale);
    void del();
};


#endif
