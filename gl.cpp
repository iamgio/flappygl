#include <GL/glew.h>

void draw(GLuint vertexBuffer, GLuint colorBuffer, int vertexCount) {
    // 1st attribute buffer : vertices
    glEnableVertexAttribArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glVertexAttribPointer(
            0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
            3,                  // size
            GL_FLOAT,           // type
            GL_FALSE,       // normalized
            0,      // stride
            nullptr            // array buffer offset
    );

    // 2nd attribute buffer : colors
    glEnableVertexAttribArray(1);
    glBindBuffer(GL_ARRAY_BUFFER, colorBuffer);
    glVertexAttribPointer(
            1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
            3,                                // size
            GL_FLOAT,                         // type
            GL_FALSE,                     // normalized?
            0,                                // stride
            nullptr                          // array buffer offset
    );

    // Draw the triangle
    glDrawArrays(GL_TRIANGLE_FAN, 0, vertexCount); // Starting from vertex 0; 3 vertices total -> 1 triangle

    glDisableVertexAttribArray(0);
    glDisableVertexAttribArray(1);
}

GLuint setupVAO() {
    GLuint VertexArrayID;
    glGenVertexArrays(1, &VertexArrayID);
    glBindVertexArray(VertexArrayID);

    return VertexArrayID;
}

GLuint newBuffer(const void *data, GLsizeiptr size) {
    GLuint buffer;
    // Generate 1 buffer, put the resulting identifier in vertexbuffer
    glGenBuffers(1, &buffer);
    // The following commands will talk about our 'vertexbuffer' buffer
    glBindBuffer(GL_ARRAY_BUFFER, buffer);
    // Give our vertices to OpenGL.
    glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

    return buffer;
}