#include "pyramid.hpp"

/**
    * @brief Constructor to initialize a 3D Pyramid.
    * 
    * The constructor defines the vertices, indices, and color of the shape automatically.
    */
Pyramid::Pyramid(float xOffset, float yOffset, float zOffset)
{
    std::cout << "Pyramid." << std::endl;

    this->shapesTriangles = 4;

    // Define the vertices of a square, each consisting of x, y, and z coordinates
    this->vertices = {
        // Base
        -0.5f + xOffset, 0.0f + yOffset, -0.5f + zOffset,
        0.5f + xOffset, 0.0f + yOffset, -0.5f + zOffset,
        0.0f + xOffset, 0.0f + yOffset,  0.5f + zOffset,

        // Apex
        0.0f + xOffset, 0.5f + yOffset, 0.0f + zOffset
    };

    this->indices = {
        // Base
        0, 1, 2,

        // Sides
        0, 1, 3,
        1, 2, 3,
        2, 0, 3,
    };

    this->initBuffers();
}
