#ifndef INPUT_HPP
#define INPUT_HPP

#include "render.hpp"

// process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly
// ---------------------------------------------------------------------------------------------------------
void processInput(unsigned char key, int x, int y)
{
    if (key == 27) {  // ESC key
        exit(0);  // Terminate program
    }

}

#endif
