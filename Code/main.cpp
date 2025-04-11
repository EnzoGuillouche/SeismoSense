#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include <optional>
#include <vector>
#include <iostream>

#include "Include/input.hpp"
#include "Include/shader.hpp"
#include "Include/Shape/shape.hpp"
#include "Include/render.hpp"

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

void terminateProgram(std::optional<std::string> message, std::optional<std::vector<Shape*>> shapes, int EXIT_CODE)
{
    if (message) std::cout << *message << std::endl;

    shapes.reset();
    glfwTerminate();
    exit(EXIT_CODE);
}

// Whenever the window size changed (by OS or user resize) this callback function executes
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    // make sure the viewport matches the new window dimensions; note that width and 
    // height will be significantly larger than specified on retina displays.
    glViewport(0, 0, width, height);
}

void initWindow(GLFWwindow*& window)
{
    std::cout << "Initializing the window..." << std::endl;

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    #endif

    // glfw window creation
    window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "SeismoSense", NULL, NULL);
    if (window == NULL)
    {
        terminateProgram("Failed to create GLFW window", std::nullopt, EXIT_FAILURE);
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
}

void initShaders(Shape& shape)
{
    std::cout << "Initializing the shaders..." << std::endl;

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * shape.getVertices().size(), shape.getVertices().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(float) * shape.getIndices().size(), shape.getIndices().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // note that this is allowed, the call to glVertexAttribPointer registered VBO as the vertex attribute's bound vertex buffer object so afterwards we can safely unbind
    glBindBuffer(GL_ARRAY_BUFFER, 0); 

    // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, but this rarely happens. Modifying other
    // VAOs requires a call to glBindVertexArray anyways so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
    glBindVertexArray(0); 

    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE); // draw in wireframe polygons
}

int main()
{
    GLFWwindow* window = nullptr;
    initWindow(window);

    unsigned int shaderProgram = buildShaders();

    Shape* square = new Shape(0);
    std::vector<Shape*> shapes;
    shapes.push_back(square);

    initShaders(*square);

    // render loop
    std::cout << "Render loop" << std::endl;
    while (!glfwWindowShouldClose(window))
    {
        processInput(window, square); // input

        render(window, shaderProgram, *square); // render
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    
    terminateProgram(std::nullopt, shapes, EXIT_SUCCESS);
}
