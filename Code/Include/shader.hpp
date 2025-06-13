#pragma once

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <iostream>
#include <fstream>
#include <sstream>

/**
    * Reads the content of a shader file and returns it as a null-terminated C-string.
    * The returned memory is dynamically allocated and should be freed manually.
    *
    * @param filename Path to the shader file.
    * @return Pointer to the shader source as a C-string, or nullptr if the file couldn't be opened.
    */
const char* readShaderFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Failed to open file: " << filename << std::endl;
        return nullptr;
    }

    std::stringstream buffer;
    buffer << file.rdbuf();  // Read entire file content into buffer

    std::string content = buffer.str();
    char* shaderSource = new char[content.length() + 1];
    std::copy(content.begin(), content.end(), shaderSource);
    shaderSource[content.length()] = '\0';  // Null-terminate the string

    return shaderSource;
}

// OpenGL buffer object handles
unsigned int VBO, VAO, EBO;

/**
    * @brief Builds and compiles the vertex and fragment shaders, then links them into a shader program.
    * 
    * @return GLuint identifier of the created shader program.
    */
GLuint buildShaders() {
    // Load shader source code from files
    const char* vertexShaderSource   = readShaderFile("Shaders/shader.vert");
    const char* fragmentShaderSource = readShaderFile("Shaders/shader.frag");

    // -----------------------------
    // Vertex Shader Compilation
    // -----------------------------
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);                     // Create shader object
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);                       // Attach source
    glCompileShader(vertexShader);                                                    // Compile shader

    // Check for compilation errors
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // -----------------------------
    // Fragment Shader Compilation
    // -----------------------------
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);                 // Create shader object
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);                   // Attach source
    glCompileShader(fragmentShader);                                                  // Compile shader

    // Check for compilation errors
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    // -----------------------------
    // Shader Program Linking
    // -----------------------------
    unsigned int shaderProgram = glCreateProgram();                                   // Create program
    glAttachShader(shaderProgram, vertexShader);                                      // Attach compiled vertex shader
    glAttachShader(shaderProgram, fragmentShader);                                    // Attach compiled fragment shader
    glLinkProgram(shaderProgram);                                                     // Link both shaders into final program

    // Check for linking errors
    glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    // Clean up the shaders as they're now linked into the program
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

GLuint buildTextShaders() {
    const char* vertexShaderSource = readShaderFile("Shaders/shaderText.vert");
    const char* fragmentShaderSource = readShaderFile("Shaders/shaderText.frag");

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    int success;
    char infoLog[512];
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
        std::cerr << "ERROR::TEXT::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
        std::cerr << "ERROR::TEXT::FRAGMENT::COMPILATION_FAILED\n" << infoLog << std::endl;
    }

    GLuint textShaderProgram = glCreateProgram();
    glAttachShader(textShaderProgram, vertexShader);
    glAttachShader(textShaderProgram, fragmentShader);
    glLinkProgram(textShaderProgram);
    glGetProgramiv(textShaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(textShaderProgram, 512, NULL, infoLog);
        std::cerr << "ERROR::TEXT::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
    }

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
    
    glm::mat4 projection = glm::ortho(0.0f, (float)SCR_WIDTH, 0.0f, (float)SCR_HEIGHT);

    glUseProgram(textShaderProgram);
    glUniformMatrix4fv(glGetUniformLocation(textShaderProgram, "projection"), 1, GL_FALSE, glm::value_ptr(projection));

    return textShaderProgram;
}