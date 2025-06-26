#pragma once

#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>

#include "Shape/shape.hpp"
#include "camera.hpp"

int moveTab = 0; // 0 = no change / 1 = open / 2 = close

/**
    * @brief Processes keyboard input to control the movement of a shape's vertices and window state    
    * 
    * @param window Pointer to the GLFW window being used, which allows us to capture user input.
    * @param camera Reference of a Camera object whose coordinates will be updated based on keyboard input.
    */
void inputCamera(GLFWwindow *window, Camera& camera)
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

void inputEvent(GLFWwindow *window, Rectangle* tab)
{
    static bool pKeyPressedLastFrame = false;

    if (glfwGetKey(window, GLFW_KEY_P) == GLFW_PRESS)
    {
        if (!pKeyPressedLastFrame)
        {
            pKeyPressedLastFrame = true;

            if (moveTab == 0)
            {
                if (tab->getPos()[0] == SCR_WIDTH)
                {
                    moveTab = 1;
                } 
                else if (tab->getPos()[0] == SCR_WIDTH - 250.0f)
                {
                    moveTab = 2;
                }
            }
        }
    }
    else
    {
        pKeyPressedLastFrame = false; // key is released
    }
}

void processInput(GLFWwindow* window, unsigned int shaderProgram, unsigned int textShaderProgram, std::vector<Shape*> shapes, Rectangle* tab, Text* tabText, Camera& camera)
{
    // TAB
    // open tab
    if (moveTab == 1 && tab->getPos()[0] != SCR_WIDTH-250.0f)
    {
        tab->setPos({tab->getPos()[0]-50, tab->getPos()[1]}, tab->getSize());
        tabText->setPos({tabText->getPos()[0]-50, tabText->getPos()[1]});
        renderLoop(window, shaderProgram, textShaderProgram, shapes, tab, tabText, camera); 
    } 
    // close tab
    else if (moveTab == 2 && tab->getPos()[0] != SCR_WIDTH)
    {
        tab->setPos({tab->getPos()[0]+50, tab->getPos()[1]}, tab->getSize());
        tabText->setPos({tabText->getPos()[0]+50, tabText->getPos()[1]});
        renderLoop(window, shaderProgram, textShaderProgram, shapes, tab, tabText, camera); 
    } 
    else 
    {
        moveTab = 0;
    }
}