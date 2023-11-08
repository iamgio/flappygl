#version 330 core

out vec3 color;

in vec3 fragmentColor;

#define POINT_FREQUENCY 300
#define POINT_SIZE 200

void main() {
    if (int(gl_FragCoord.x * gl_FragCoord.y / 300) % POINT_FREQUENCY <= POINT_SIZE) {
        // Curve patterns
        color = vec3(0.82, 0.82, 0.7);
    } /*else if (int(gl_FragCoord.x * gl_FragCoord.y * gl_FragCoord.x) % POINT_Y_FREQUENCY <= POINT_SIZE) {
        // Noise patterns
        color = vec3(0.58, 0.91, 0.96);
    }*/ else {
        color = vec3(0.92, 0.87, 0.81);
    }
}