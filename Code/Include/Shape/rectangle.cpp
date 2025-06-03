#include "rectangle.hpp"

Rectangle::Rectangle(float xPos, float yPos, float xSize, float ySize, std::vector<float> colors) : Shape(GL_FILL, colors) 
{
    this->shapesTriangles = 2;

    // Define the vertices of a rectangle, each consisting of x, y, and z coordinates
    this->vertices = {
        xPos+xSize, yPos, 0.0f, // 0
        xPos, yPos, 0.0f, // 1
        xPos, yPos+ySize, 0.0f, // 2
        xPos+xSize, yPos+ySize, 0.0f // 3
    };

    this->indices = {
        0, 1, 3,
        1, 2, 3
    };

    this->initBuffers();
};