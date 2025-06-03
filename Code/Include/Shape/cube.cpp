#include "cube.hpp"

/**
    * @brief Constructor to initialize a 3D Cube.
    * 
    * The constructor defines the vertices, indices, and color of the shape automatically.
    */
Cube::Cube(float xOffset, float yOffset, float zOffset, std::vector<float> colors) : Shape(GL_LINE, colors)
{
    std::cout << "Cube." << std::endl;

    this->shapesTriangles = 12;

    // Define the vertices of a square, each consisting of x, y, and z coordinates
    this->vertices = {
        // Bottom
        -0.25f + xOffset, -0.25f + yOffset, -0.25f + zOffset,
        0.25f + xOffset, -0.25f + yOffset, -0.25f + zOffset,
        0.25f + xOffset, -0.25f + yOffset, 0.25f + zOffset,
        -0.25f + xOffset, -0.25f + yOffset, 0.25f + zOffset,

        // Top
        -0.25f + xOffset, 0.25f + yOffset, -0.25f + zOffset,
        0.25f + xOffset, 0.25f + yOffset, -0.25f + zOffset,
        0.25f + xOffset, 0.25f + yOffset, 0.25f + zOffset,
        -0.25f + xOffset, 0.25f + yOffset, 0.25f + zOffset,
    };

    this->indices = {
        // Bottom Base
        0, 1, 2,
        0, 3, 2,

        // Top Base
        4, 5, 6,
        4, 7, 6,

        // Sides
        2, 3, 7,
        2, 6, 7,
        1, 0, 4,
        1, 5, 4,
        6, 5, 1,
        6, 2, 1,
        7, 4, 0,
        7, 3, 0
    };

    this->initBuffers();
}
