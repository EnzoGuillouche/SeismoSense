#ifndef RENDER_HPP
#define RENDER_HPP

#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>

#include "shader.hpp"

void render(GLFWwindow* window, unsigned int shaderProgram, float redValue, float greenValue, float blueValue) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glUseProgram(shaderProgram);

    int vertexColorLocation = glGetUniformLocation(shaderProgram, "color");
    glUniform4f(vertexColorLocation, redValue, greenValue, blueValue, 1.0f);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    // glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
    // -------------------------------------------------------------------------------
    glfwSwapBuffers(window);
    glfwPollEvents();
}

#endif
