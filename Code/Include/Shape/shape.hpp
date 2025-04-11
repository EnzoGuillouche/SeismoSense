#pragma once

/**
    * @brief Represents a 3D shape with parameters and the ability to update those parameters.
    * 
    * This class stores the geometric properties of a shape, including its vertices, triangles, 
    * and color information. It provides functions to retrieve and update these properties, 
    * enabling dynamic manipulation of the shape.
    */
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



