#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include "Include/render.hpp"

Renderer::Renderer() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
}

void Renderer::render(Shader &shader, float *color) {
    glClearColor(color[0], color[1], color[2], color[3]);
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
    shader.setVec4("uColor", color[0], color[1], color[2], color[3]); // Send color to shader

    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
