#ifndef RENDER_HPP
#define RENDER_HPP

#include <GL/glut.h>  // OpenGL (GLUT)
#include "physics.hpp"

// OpenGL display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Get Bullet physics transformation
    btTransform transform;
    boxBody->getMotionState()->getWorldTransform(transform);
    
    // Extract position
    btScalar matrix[16];
    transform.getOpenGLMatrix(matrix);

    // Render box
    glPushMatrix();
    glMultMatrixf(matrix);  // Apply physics transformation
    glutSolidCube(1.0);  // Render a 1x1x1 cube
    glPopMatrix();

    glutSwapBuffers();
}

#endif
