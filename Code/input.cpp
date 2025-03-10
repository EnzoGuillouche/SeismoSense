#define GL_SILENCE_DEPRECATION
#include "Include/input.hpp"
#include <algorithm>

InputHandler::InputHandler() : red(0.0f), green(0.0f), blue(0.0f), transparency(1.0f) {}

void InputHandler::processInput(GLFWwindow* window) {
    float increment = 0.02f;
    
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) red = std::min(1.0f, red + increment);
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) green = std::min(1.0f, green + increment);
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) blue = std::min(1.0f, blue + increment);
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) transparency = std::min(1.0f, transparency + increment);
    } 
    
    if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS) red = std::max(0.0f, red - increment);
        if (glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS) green = std::max(0.0f, green - increment);
        if (glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS) blue = std::max(0.0f, blue - increment);
        if (glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS) transparency = std::max(0.0f, transparency - increment);
    }
}
