#pragma once

#include "iostream"
#include "vector"

class Shape
{
private:
    // Each vertex consists of 3 floats: x, y, z
    std::vector<float> vertices;

    // Number of triangles of the shape
    int shapesTriangles;

    // Indices specifying triangles from the above vertices
    std::vector<unsigned int> indices;

    // Color scheme
    std::vector<float> colors;
public:
    Shape(int shapeId);
    ~Shape();

    std::vector<float> getVertices() const;
    int getShapesTriangles() const;
    std::vector<unsigned int> getIndices() const;
    std::vector<float> getColors() const;

    void updateVertices(int index, float changeAmount);
};



