#include "text.h"

Text::Text() {

    //setColor(1.0f, 1.0f, 1.0f);
}

void Text::setColor(float r, float g, float b) {
    gltColor(r, g, b, 1.0f);
}

void Text::setText(const char *string) {
    gltSetText(this->text, string);
}

void Text::draw(float x, float y, float scale) {
    GLTtext *text = gltCreateText();
    gltSetText(text, "Hello World!");

    // Begin text drawing (this for instance calls glUseProgram)
    gltBeginDraw();

    gltDrawText2D(text, .0f, .0f, 20.0f);

// Finish drawing text
    gltEndDraw();

    // Begin text drawing
    gltBeginDraw();

    // Draw
    gltDrawText2D(text, x, y, scale);

    // Finish drawing text
    gltEndDraw();
}

void Text::del() {
    gltDeleteText(this->text);
}

