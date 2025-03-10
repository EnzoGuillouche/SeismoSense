#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <GLFW/glfw3.h>

class Shader {
public:
    unsigned int ID;

    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void setVec4(const std::string &name, float x, float y, float z, float w);
    void setVec4(const std::string &name, float x, float y, float z, float w) const {
        glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w);
    }
};

#endif
