#include "square.hpp"

Square::Square(float xOffset, float yOffset, float zOffset, std::vector<float> colors) : Shape(GL_LINE, colors)
{
    this->shapesTriangles = 2;

    // Define the vertices of a square, each consisting of x, y, and z coordinates
    this->vertices = {
        0.5f + xOffset, 0.5f + yOffset, 0.0f + zOffset,
        0.5f + xOffset, -0.5f + yOffset, 0.0f + zOffset,
        -0.5f + xOffset, -0.5f + yOffset, 0.0f + zOffset,
        -0.5f + xOffset, 0.5f + yOffset, 0.0f + zOffset
    };

    this->indices = {
        0, 1, 3,
        1, 2, 3
    };

    this->initBuffers();
};