#include "square.hpp"

Square::Square() {
    this->shapesTriangles = 2;

    // Define the vertices of a square, each consisting of x, y, and z coordinates
    this->vertices = {
        0.5f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
        -0.5f, 0.5f, 0.0f
    };

    this->indices = {
        0, 1, 3,
        1, 2, 3
    };

    this->initBuffers();
};