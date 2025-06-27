#pragma once

#include "Shape/rectangle.hpp"
#include "character.hpp"

struct Tab
{
    Rectangle& tabObject;
    std::vector<Text*> texts;

    Tab(Rectangle& rect) : tabObject(rect) {}
};
