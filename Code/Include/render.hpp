#pragma once

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "shader.hpp"

constexpr float BACKGROUND_COLOR[3] = { 0.0f, 0.0f, 0.0f };

/**
    * @brief Renders a frame by setting the background color, activating the shader program,
    *        sending a color uniform, binding buffers, and drawing the shape.
    * 
    * @param window Pointer to the GLFW window used for rendering.
    * @param shaderProgram OpenGL shader program ID used to render the shape.
    * @param shape Shape object containing the vertex and color data for rendering.
    */
void render(GLFWwindow* window, unsigned int shaderProgram, Shape& shape) {
    glUseProgram(shaderProgram);

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::rotate(model, glm::radians(shape.getRotationX()), glm::vec3(1.0f, 0.0f, 0.0f));
    model = glm::rotate(model, glm::radians(shape.getRotationY()), glm::vec3(0.0f, 1.0f, 0.0f));
    model = glm::rotate(model, glm::radians(shape.getRotationZ()), glm::vec3(0.0f, 0.0f, 1.0f));

    glm::mat4 view = glm::translate(glm::mat4(1.0f), glm::vec3(0.0f, 0.0f, -2.0f));
    glm::mat4 projection = glm::perspective(glm::radians(45.0f), (float)SCR_WIDTH / SCR_HEIGHT, 0.1f, 100.0f);

    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "model"), 1, GL_FALSE, glm::value_ptr(model));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "view"), 1, GL_FALSE, glm::value_ptr(view));
    glUniformMatrix4fv(glGetUniformLocation(shaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    int vertexColorLocation = glGetUniformLocation(shaderProgram, "color");
    glUniform4f(vertexColorLocation, shape.getColors()[0], shape.getColors()[1], shape.getColors()[2], 1.0f);

    shape.draw();
}

void renderText(unsigned int shaderProgram, Text& text, float scale, glm::vec3 color) {
    // First, we compute total width of the text
    float textWidth = 0.0f;
    for (char c : text.getText()) {
        Character ch = text.getCharacters()[c];
        textWidth += (ch.advance >> 6) * scale;
    }

    // Center the text horizontally at (x, y)
    float startX = text.getPos()[0] - textWidth / 2.0f;

    glUseProgram(shaderProgram);
    glUniform3f(glGetUniformLocation(shaderProgram, "textColor"), color.x, color.y, color.z);
    glActiveTexture(GL_TEXTURE0);
    glBindVertexArray(text.getVAO());

    for (char c : text.getText()) {
        Character ch = text.getCharacters()[c];

        float xpos = startX + ch.bearing.x * scale;
        float ypos = text.getPos()[1] - (ch.size.y - ch.bearing.y) * scale;

        float w = ch.size.x * scale;
        float h = ch.size.y * scale;

        float vertices[6][4] = {
            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos,     ypos,       0.0f, 1.0f },
            { xpos + w, ypos,       1.0f, 1.0f },

            { xpos,     ypos + h,   0.0f, 0.0f },
            { xpos + w, ypos,       1.0f, 1.0f },
            { xpos + w, ypos + h,   1.0f, 0.0f }
        };

        glBindTexture(GL_TEXTURE_2D, ch.textureID);
        glBindBuffer(GL_ARRAY_BUFFER, text.getVBO());
        glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(vertices), vertices);
        glDrawArrays(GL_TRIANGLES, 0, 6);

        startX += (ch.advance >> 6) * scale;
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
