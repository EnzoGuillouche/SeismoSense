#include "Include/input.hpp"

// Bullet physics update function
void update(int value) {
    dynamicsWorld->stepSimulation(1.0f / 60.0f);  // Advance physics simulation
    glutPostRedisplay();  // Redraw scene
    glutTimerFunc(16, update, 0);
}



// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("SeismoSense");
    // glutFullScreen();

    glEnable(GL_DEPTH_TEST);
    init();
    
    glutDisplayFunc(display);
    glutKeyboardFunc(processInput);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
