#include "triangle.hpp"

Triangle::Triangle() {
        this->shapesTriangles = 1;

        // Define the vertices of a Triangle, each consisting of x, y, and z coordinates
        std::vector<float> vertices = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.0f,
            -0.5f, -0.5f, 0.0f,
        };

        std::vector<unsigned int> indices = {
            0, 1, 2,
        };
    };