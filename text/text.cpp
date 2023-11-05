#define GLT_IMPLEMENTATION
#include "text.h"

Text::Text() {
    this->text = gltCreateText();
    //setColor(1.0f, 1.0f, 1.0f);
}

void Text::setColor(float r, float g, float b) {
    gltColor(r, g, b, 1.0f);
}

void Text::setText(const char *string) {
    gltSetText(this->text, string);
}

void Text::draw(float x, float y, float scale) {
    gltBeginDraw();
    gltDrawText2D(this->text, .0f, .0f, 10.0f);
    gltEndDraw();
}

void Text::del() {
    gltDeleteText(this->text);
}

