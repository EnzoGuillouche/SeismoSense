#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "Shape/shape.hpp"

/**
    * @brief Processes keyboard input and updates the window state or vertex positions accordingly.
    * 
    * @param window Pointer to the GLFW window being used.
    */
void processInput(GLFWwindow *window, Shape* shape)
{
    // Close the window if the ESC key is pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Move the shape's vertices according to the user input
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        for (int i = 0; i < 12; i += 3) {
            shape->updateVertices(i+1, 0.02f);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        for (int i = 0; i < 12; i += 3) {
            shape->updateVertices(i+1, -0.02f);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        for (int i = 0; i < 12; i += 3) {
            shape->updateVertices(i, -0.02f);
        }
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        for (int i = 0; i < 12; i += 3) {
            shape->updateVertices(i, 0.02f);
        }
    }
}
