#include "iostream"
#include "vector"

#include "shape.hpp"

/**
    * @brief Constructor to initialize a shape based on the given ID.
    * 
    * The constructor defines the vertices, indices, and color of the shape based on the provided shapeId.
    * It currently supports the "Square" shape.
    * 
    * @param shapeId Integer representing the shape type:
    * 
    * - 0 = Square
    */
Shape::Shape(int shapeId)
{
    std::cout << "Constructing ";
    
    // Switch statement to set properties based on the shapeId
    switch (shapeId)
    {
    case 0:
        std::cout << "Triangle." << std::endl;

        this->shapesTriangles = 1;

        // Define the vertices of a square, each consisting of x, y, and z coordinates
        this->vertices = {
            0.0f, 0.5f, 0.0f,
            0.5f, -0.5f, 0.5f,
            -0.5f, -0.5f, -0.5f,
        };

        this->indices = {
            0, 1, 2,
        };
        break;
    case 1:
        std::cout << "Square." << std::endl;

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
        break;
    
    default:
        std::cerr << " of the shape not allowed: '" << shapeId << "' is out of shapes range." << std::endl;
        break;
    }

    this->colors = {
        0.0f, 1.0f, 0.0f
    };
}

/**
    * @brief Destructor to clean up the resources used by the Shape.
    * 
    */
Shape::~Shape()
{
    vertices.clear();
    indices.clear();
}

/**
    * @brief Updates the vertex at the given index by adding a specified change amount.
    * 
    * This method allows the modification of a specific vertex's coordinate (x, y, or z) in the vertices array.
    * The changeAmount is added to the existing value of the vertex at the specified index.
    * 
    * @param index The index of the vertex to update.
    * @param changeAmount The amount to change the vertex's coordinate value.
    */
void Shape::updateVertices(int index, float changeAmount) 
{
    for (int i = 0; i < this->vertices.size(); i += 3) {
        this->vertices[i+index] += changeAmount;
    }
}

void Shape::rotate(char axis, float changeAmount) {
    switch (axis) {
        case 'x': this->rotationX += changeAmount; break;
        case 'y': this->rotationY += changeAmount; break;
        case 'z': this->rotationZ += changeAmount; break;
    }
}