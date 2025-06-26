#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include <optional>
#include <vector>
#include <map>
#include <iostream>

const unsigned int SCR_WIDTH = 800;
const unsigned int SCR_HEIGHT = 600;

#include "Include/shader.hpp"
#include "Include/camera.hpp"
#include "Include/character.hpp"
#include "Include/render.hpp"
#include "Include/input.hpp"

#include "Include/Shape/shape.hpp"
#include "Include/Shape/rectangle.hpp"
#include "Include/Shape/triangle.hpp"
#include "Include/Shape/square.hpp"
#include "Include/Shape/pyramid.hpp"
#include "Include/Shape/cube.hpp"

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

    glEnable(GL_DEPTH_TEST); // for 3D rendering

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);
    // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * shape.getVertices().size(), shape.getVertices().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * shape.getIndices().size(), shape.getIndices().data(), GL_STATIC_DRAW);

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

    GLuint shaderProgram = buildShaders();
    GLuint textShaderProgram = buildTextShaders();

    Camera camera;

    // tab
    Rectangle* tab = new Rectangle(SCR_WIDTH-250.0f, 0, 250.0f, SCR_HEIGHT, { 0, 0, 1.0f });
    // create text for tab
    Text* tabText = new Text("Simulation", { SCR_WIDTH/6.0f*5+8, SCR_HEIGHT-50 }, textVAO, textVBO);

    // simulation shapes
    std::vector<Shape*> shapes;

    int floors = 3;

    float yOffset = 0;
    for (int i = 0; i < floors; i++)
    {

        Shape* shape = new Cube(0, yOffset, 0, { 0, 1.0f, 0 });
        shapes.push_back(shape);
        Shape* shape1 = new Cube(0, yOffset, -0.5f, { 0, 1.0f, 0 });
        shapes.push_back(shape1);
        Shape* shape2 = new Cube(0.5f, yOffset, 0, { 0, 1.0f, 0 });
        shapes.push_back(shape2);
        Shape* shape3 = new Cube(0.5f, yOffset, -0.5f, { 0, 1.0f, 0 });
        shapes.push_back(shape3);
        
        yOffset+=0.5f;
    }

    std::cout << "Initialization complete." << std::endl;

    // render loop
    while (!glfwWindowShouldClose(window))
    {
        inputCamera(window, camera);
        inputEvent(window, tab);
        processInput(window, shaderProgram, textShaderProgram, shapes, tab, tabText, camera);

        renderLoop(window, shaderProgram, textShaderProgram, shapes, tab, tabText, camera);
    }

    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);
    
    terminateProgram(std::nullopt, shapes, EXIT_SUCCESS);
}
