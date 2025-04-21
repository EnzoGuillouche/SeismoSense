#include "pyramid.hpp"

/**
    * @brief Constructor to initialize a 3D Pyramid.
    * 
    * The constructor defines the vertices, indices, and color of the shape automatically.
    */
Pyramid::Pyramid()
{
    std::cout << "Pyramid." << std::endl;

    this->shapesTriangles = 4;

    // Define the vertices of a square, each consisting of x, y, and z coordinates
    this->vertices = {
        // Base
        -0.5f, 0.0f, -0.5f,
        0.5f, 0.0f, -0.5f,
        0.0f, 0.0f,  0.5f,

        // Apex
        0.0f, 0.5f, 0.0f
    };

    this->indices = {
        // Base
        0, 1, 2,

        // Sides
        0, 1, 3,
        1, 2, 3,
        2, 0, 3,
    };
}
