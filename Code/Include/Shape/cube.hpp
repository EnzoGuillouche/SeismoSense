#pragma once

#include "shape.hpp"

/**
    * @brief Represents a 3D Cube with parameters and the ability to update those parameters. 
    * 
    * Inherits from the `Shape` class.
    * 
    * This class stores the geometric properties of a shape, including its vertices, triangles, 
    * and color information. It provides functions to retrieve and update these properties, 
    * enabling dynamic manipulation of the shape.
    */
class Cube : public Shape
{
public:
    Cube(float xOffset, float yOffset, float zOffset);
};
