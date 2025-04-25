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

// Initiates the shaders for the shape
void Shape::initBuffers() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
    glGenBuffers(1, &this->EBO);

    glBindVertexArray(this->VAO);

    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(float) * this->getVertices().size(), this->getVertices().data(), GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(unsigned int) * this->getIndices().size(), this->getIndices().data(), GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindVertexArray(0);
}

// Draws the shape
void Shape::draw() {
    glBindVertexArray(this->VAO);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glDrawElements(GL_TRIANGLES, getIndices().size(), GL_UNSIGNED_INT, 0);
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
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(float) * this->vertices.size(), this->vertices.data());
}

void Shape::rotate(char axis, float changeAmount) {
    switch (axis) {
        case 'x': this->rotationX += changeAmount; break;
        case 'y': this->rotationY += changeAmount; break;
        case 'z': this->rotationZ += changeAmount; break;
    }
}