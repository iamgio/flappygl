#version 330 core

out vec3 color;

// Interpolated values from the vertex shaders
in vec3 fragmentColor;

void main() {
    // Changes ground color interpolation
    if (fragmentColor.z > 0.45) {
        color = vec3(0.7f + fragmentColor.z / 4, 0.87f, fragmentColor.z);
    } else {
        color = fragmentColor;
    }
}