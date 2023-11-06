#version 330 core

out vec3 color;

// Interpolated values from the vertex shaders
in vec3 fragmentColor;

void main() {
    color = fragmentColor;
}