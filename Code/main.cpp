#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <iostream>

float redColorRenderingValue = 0.0f;
float greenColorRenderingValue = 0.0f;
float blueColorRenderingValue = 0.0f;
float transparancyRenderingValue = 100.0f;

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

void processInput(GLFWwindow *window)
{
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    else if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS)
    {
        if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
            redColorRenderingValue += 5.0f;
        if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
            greenColorRenderingValue += 5.0f;
        if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
            blueColorRenderingValue += 5.0f;
        if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
            transparancyRenderingValue += 5.0f;
    }
    else if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS)
    {
        if(glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
            redColorRenderingValue -= 5.0f;
        if(glfwGetKey(window, GLFW_KEY_G) == GLFW_PRESS)
            greenColorRenderingValue -= 5.0f;
        if(glfwGetKey(window, GLFW_KEY_B) == GLFW_PRESS)
            blueColorRenderingValue -= 5.0f;
        if(glfwGetKey(window, GLFW_KEY_T) == GLFW_PRESS)
            transparancyRenderingValue -= 5.0f;
    }
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW!" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(800, 600, "SeismoSense", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window!" << std::endl;
        glfwTerminate();
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // Main loop
    while (!glfwWindowShouldClose(window)) {
        // Handle input
        processInput(window);

        // Rendering
        glClearColor(redColorRenderingValue / 255.0f, greenColorRenderingValue / 255.0f, blueColorRenderingValue / 255.0f, transparancyRenderingValue / 100.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // Swap buffers and poll IO events
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
