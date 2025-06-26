#include "rectangle.hpp"

Rectangle::Rectangle(float xPos, float yPos, float xSize, float ySize, std::vector<float> colors) : Shape(GL_FILL, colors) 
{
    this->shapesTriangles = 2;

    this->setPos({xPos, yPos}, {xSize, ySize});
};

void Rectangle::setPos(std::vector<float> newPos, std::vector<float> newSize)
{
    this->pos = newPos;
    this->size = newSize;

    // Define the vertices of a rectangle, each consisting of x, y, and z coordinates
    this->vertices = {
        this->pos[0]+this->size[0], this->pos[1], 0.0f, // 0
        this->pos[0], this->pos[1], 0.0f, // 1
        this->pos[0], this->pos[1]+this->size[1], 0.0f, // 2
        this->pos[0]+this->size[0], this->pos[1]+this->size[1], 0.0f // 3
    };

    this->indices = {
        0, 1, 3,
        1, 2, 3
    };
    
    this->initBuffers();
}