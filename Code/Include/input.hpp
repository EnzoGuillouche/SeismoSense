#ifndef INPUT_HPP
#define INPUT_HPP

#include "render.hpp"
#include "keys.hpp"

// process standard input: query GLUT whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(unsigned char key, int x, int y)
{
    if (key == ESC_KEY) {
        exit(0);  // Terminate program
    }

}

// process special input: query GLUT whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processSpecialInput(int key, int x, int y)
{
    if (key == UP_KEY) {
        // clicked up key
    }

}

#endif
