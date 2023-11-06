#define GLT_IMPLEMENTATION
#define GLT_MANUAL_VIEWPORT
#include "../lib/gltext.h"
#include "text.h"

Text::Text() {
    this->text = gltCreateText();
}

void Text::setColor(float r, float g, float b) {
    gltColor(r, g, b, 1.0f);
}

void Text::setText(const char *string) {
    gltSetText(this->text, string);
}

/*void Text::draw(float x, float y, float scale) {
    gltBeginDraw();
    gltDrawText2D(text, x, y, scale);
    gltEndDraw();
}*/

void Text::del() {
    gltDeleteText(this->text);
}

