#ifndef INPUT_HPP
#define INPUT_HPP

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(GLFWwindow *window, float vertices[])
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS) {
        for (int i = 0; i < 12; i+=3) {
            vertices[i+1] += 0.02f;
        }
    } if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS) {
        for (int i = 0; i < 12; i+=3) {
            vertices[i+1] -= 0.02f;
        }
    } if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS) {
        for (int i = 0; i < 12; i+=3) {
            vertices[i] -= 0.02f;
        }
    } if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS) {
        for (int i = 0; i < 12; i+=3) {
            vertices[i] += 0.02f;
        }
    }
}

#endif
