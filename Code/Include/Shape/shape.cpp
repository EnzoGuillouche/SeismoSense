#include "shape.hpp"

/**
    * @brief Destructor to clean up the resources used by the Shape.
    * 
    */
Shape::~Shape()
{
    this->vertices.clear();
    this->indices.clear();
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