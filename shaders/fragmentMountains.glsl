#version 330 core

out vec3 color;

in vec3 fragmentColor;

#define POINT_SPACING 500
#define POINT_SIZE 250

void main() {
    if (int(gl_FragCoord.x * gl_FragCoord.y / POINT_SPACING) % POINT_SPACING <= POINT_SIZE) {
        // Curve patterns
        color = vec3(0.9, 0.82, 0.8);
    } /*else if (int(gl_FragCoord.x * gl_FragCoord.y * gl_FragCoord.x) % POINT_Y_FREQUENCY <= POINT_SIZE) {
        // Noise patterns
        color = vec3(0.58, 0.91, 0.96);
    }*/ else {
        color = vec3(0.92, 0.87, 0.85);
    }
}