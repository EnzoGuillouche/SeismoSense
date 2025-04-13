#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "Shape/shape.hpp"

/**
    * @brief Processes keyboard input to control the movement of a shape's vertices and window state    
    * 
    * @param window Pointer to the GLFW window being used, which allows us to capture user input.
    * @param shape Pointer to a Shape object whose vertices will be updated based on keyboard input.
    */
void processInput(GLFWwindow *window, Shape* shape)
{
    // Close the window if the ESC key is pressed
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Move the shape's vertices according to the user input
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        shape->updateVertices(1, 0.02f);
    }
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        shape->updateVertices(1, -0.02f);
    }
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        shape->updateVertices(0, -0.02f);
    }
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        shape->updateVertices(0, 0.02f);
    }
}
