#ifndef INPUT_HPP
#define INPUT_HPP

#include <GLFW/glfw3.h>

class InputHandler {
private:
    float red, green, blue, transparency;
public:
    InputHandler();
    void processInput(GLFWwindow* window);
    float getRed() const { return red; }
    float getGreen() const { return green; }
    float getBlue() const { return blue; }
    float getTransparency() const { return transparency; }
};

#endif
