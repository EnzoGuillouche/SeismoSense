#pragma once

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

#include "shader.hpp"

constexpr float BACKGROUND_COLOR[3] = { 0.0f, 0.0f, 0.0f };

/**
    * @brief Renders a frame by setting the background color, activating the shader program,
    *        sending a color uniform, binding buffers, and drawing the shape.
    * 
    * @param window Pointer to the GLFW window used for rendering.
    * @param shaderProgram OpenGL shader program ID used to render the shape.
    * @param shapesTriangles Number of indices to draw (e.g., 6 for two triangles forming a quad).
    * @param redValue Red channel value for the shape color (0.0f to 1.0f).
    * @param greenValue Green channel value for the shape color (0.0f to 1.0f).
    * @param blueValue Blue channel value for the shape color (0.0f to 1.0f).
    */
void render(GLFWwindow* window, unsigned int shaderProgram, int shapesTriangles, float redValue, float greenValue, float blueValue) {
    glClearColor(BACKGROUND_COLOR[0], BACKGROUND_COLOR[1], BACKGROUND_COLOR[2], 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    // Retrieve the location of the uniform variable "color" in the shader
    int vertexColorLocation = glGetUniformLocation(shaderProgram, "color");

    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);

    glDrawElements(GL_TRIANGLES, shapesTriangles*3, GL_UNSIGNED_INT, 0);

    glfwSwapBuffers(window);
    glfwPollEvents();
}
