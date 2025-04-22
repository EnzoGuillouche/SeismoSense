#include "triangle.hpp"

Triangle::Triangle() {
    this->shapesTriangles = 1;

    // Define the vertices of a Triangle, each consisting of x, y, and z coordinates
    this->vertices = {
        0.0f, 0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        -0.5f, -0.5f, 0.0f,
    };

    this->indices = {
        0, 1, 2,
    };
};