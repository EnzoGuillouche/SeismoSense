#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "Shape/shape.hpp"
#include "camera.hpp"

/**
    * @brief Processes keyboard input to control the movement of a shape's vertices and window state    
    * 
    * @param window Pointer to the GLFW window being used, which allows us to capture user input.
    * @param camera Reference of a Camera object whose coordinates will be updated based on keyboard input.
    */
void processInput(GLFWwindow *window, Camera& camera)
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        camera.moveForward();
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        camera.moveBackward();
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        camera.moveLeft();
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        camera.moveRight();
    if (glfwGetKey(window, GLFW_KEY_SPACE) == GLFW_PRESS)
        camera.moveUp();
    if (glfwGetKey(window, GLFW_KEY_LEFT_SHIFT) == GLFW_PRESS)
        camera.moveDown();
}

