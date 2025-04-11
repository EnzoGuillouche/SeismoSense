#include "shape.hpp"

Shape::Shape(int shapeId)
{
    std::cout << "Constructing ";
    switch (shapeId)
    {
    case 0:
        std::cout << "Square." << std::endl;

        this->shapesTriangles = 2;

        this->vertices = {
            0.5f, 0.5f, 0.0f, // top right
            0.5f, -0.5f, 0.0f, // bottom right
            -0.5f, -0.5f, 0.0f, // bottom left
            -0.5f, 0.5f, 0.0f // top left 
        };

        this->indices = {
            0, 1, 3,
            1, 2, 3
        };
        break;
    
    default:
        break;
    }

    this->colors = {
        1.0f, 0.0f, 0.0f
    };
}

Shape::~Shape()
{
    vertices.clear();
    indices.clear();
}

std::vector<float> Shape::getVertices() const
{
    return this->vertices;
}

int Shape::getShapesTriangles() const
{
    return this->shapesTriangles;
}

std::vector<unsigned int> Shape::getIndices() const
{
    return this->indices;
}

std::vector<float> Shape::getColors() const
{
    return this->colors;
}

void Shape::updateVertices(int index, float changeAmount) 
{
    this->vertices[index] += changeAmount;
}