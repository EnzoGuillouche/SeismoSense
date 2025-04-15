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
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Zoom / Unzoom on shape 
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS)
        shape->updateVertices(2, 0.02f);
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS)
        shape->updateVertices(2, -0.02f);

    // Shape movement
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        shape->updateVertices(1, 0.02f);
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        shape->updateVertices(1, -0.02f);
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        shape->updateVertices(0, -0.02f);
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        shape->updateVertices(0, 0.02f);
        
    // Shape Rotation
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
        shape->rotate('x', -1.0f);
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
        shape->rotate('x', 1.0f);
    if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS)
        shape->rotate('y', -1.0f);
    if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS)
        shape->rotate('y', 1.0f);
    if (glfwGetKey(window, GLFW_KEY_Z) == GLFW_PRESS)
        shape->rotate('z', -1.0f);
    if (glfwGetKey(window, GLFW_KEY_X) == GLFW_PRESS)
        shape->rotate('z', 1.0f);
}
