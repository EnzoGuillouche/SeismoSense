#define GL_SILENCE_DEPRECATION
#include <iostream>
#include <GLFW/glfw3.h>
#include "Include/shader.hpp"
#include "Include/input.hpp"
#include "Include/render.hpp"

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void loop(GLFWwindow* window) {
    InputHandler input;
    Renderer renderer;
    Shader shader("vertex.glsl", "fragment.glsl");

    while (!glfwWindowShouldClose(window)) {
        input.processInput(window);

        float color[4] = {input.getRed(), input.getGreen(), input.getBlue(), input.getTransparency()};
        renderer.render(shader, color);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
}

int main() {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(800, 600, "SeismoSense", nullptr, nullptr);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    loop(window);

    glfwTerminate();
    return 0;
}
