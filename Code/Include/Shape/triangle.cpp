#include "triangle.hpp"

Triangle::Triangle(float xOffset, float yOffset, float zOffset) {
    this->shapesTriangles = 1;

    // Define the vertices of a Triangle, each consisting of x, y, and z coordinates
    this->vertices = {
        0.0f + xOffset, 0.5f + yOffset, 0.0f + zOffset,
        0.5f + xOffset, -0.5f + yOffset, 0.0f + zOffset,
        -0.5f + xOffset, -0.5f + yOffset, 0.0f + zOffset,
    };

    this->indices = {
        0, 1, 2,
    };

    this->initBuffers();
};