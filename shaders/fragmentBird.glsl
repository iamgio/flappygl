#version 330 core

out vec3 color;

// Interpolated values from the vertex shaders
in vec3 fragmentColor;

void main() {
    vec3 orange = vec3(0.84, 0.61, 0.02);
    vec3 yellow = vec3(0.78, 0.66, 0.15);

    color = mix(orange, yellow, gl_FragCoord.x / 500);
}