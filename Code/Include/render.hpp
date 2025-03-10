#ifndef RENDER_HPP
#define RENDER_HPP

#include <GLFW/glfw3.h>
#include "shader.hpp"

class Renderer {
private:
    unsigned int VAO, VBO;
public:
    Renderer();
    void render(Shader& shader, float* color);
};

#endif
