#pragma once

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>

#include "shader.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;
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
