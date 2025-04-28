#pragma once
#define GL_SILENCE_DEPRECATION
#include <OpenGL/gl3.h>
#include <GLFW/glfw3.h>

#include "iostream"
#include "vector"

/**
    * @brief Represents a 3D shape with parameters and the ability to update those parameters.
    * 
    * This class stores the geometric properties of a shape, including its vertices, triangles, 
    * and color information. It provides functions to retrieve and update these properties, 
    * enabling dynamic manipulation of the shape.
    */
class Shape
{
protected:
    int drawParam = GL_LINE;

    GLuint VAO, VBO, EBO;
    // Each vertex consists of 3 floats: x, y, z
    std::vector<float> vertices;

    // Number of triangles of the shape
    int shapesTriangles;

    // Indices specifying triangles from the above vertices
    std::vector<unsigned int> indices;

    // Color scheme
    std::vector<float> colors = {
        0.0f, 1.0f, 0.0f
    };

    // Rotation parameters
    float rotationX = 0.0f;
    float rotationY = 0.0f;
    float rotationZ = 0.0f;
public:
    Shape() {};
    ~Shape();
    void initBuffers();
    void draw();

    std::vector<float> getVertices() const { return this->vertices; };
    int getShapesTriangles() const { return this->shapesTriangles; };
    std::vector<unsigned int> getIndices() const { return this->indices; };
    std::vector<float> getColors() const { return this->colors; };
    float getRotationX() const { return this->rotationX; }
    float getRotationY() const { return this->rotationY; }
    float getRotationZ() const { return this->rotationZ; }

    void updateVertices(int index, float changeAmount);
    void rotate(char axis, float changeAmount);
    void changeDrawParam(int param);
};