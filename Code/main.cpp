#include <GL/glut.h>  // OpenGL (GLUT)
#include <btBulletDynamicsCommon.h>  // Bullet Physics

// Bullet physics world
btDiscreteDynamicsWorld* dynamicsWorld;
btRigidBody* boxBody;

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

// Bullet physics update function
void update(int value) {
    dynamicsWorld->stepSimulation(1.0f / 60.0f);  // Advance physics simulation
    glutPostRedisplay();  // Redraw scene
    glutTimerFunc(16, update, 0);
}

// Initialization
void init() {
    glEnable(GL_DEPTH_TEST);

    // Bullet physics setup
    btBroadphaseInterface* broadphase = new btDbvtBroadphase();
    btDefaultCollisionConfiguration* collisionConfig = new btDefaultCollisionConfiguration();
    btCollisionDispatcher* dispatcher = new btCollisionDispatcher(collisionConfig);
    btSequentialImpulseConstraintSolver* solver = new btSequentialImpulseConstraintSolver();
    
    dynamicsWorld = new btDiscreteDynamicsWorld(dispatcher, broadphase, solver, collisionConfig);
    dynamicsWorld->setGravity(btVector3(0, -9.81f, 0));  // Gravity

    // Create box shape
    btCollisionShape* boxShape = new btBoxShape(btVector3(0.5f, 0.5f, 0.5f));

    // Set up box motion state
    btDefaultMotionState* boxMotionState = new btDefaultMotionState(btTransform(btQuaternion(0, 0, 0, 1), btVector3(0, 2, 0)));
    btScalar mass = 1.0f;
    btVector3 inertia(0, 0, 0);
    boxShape->calculateLocalInertia(mass, inertia);

    // Create rigid body
    btRigidBody::btRigidBodyConstructionInfo boxInfo(mass, boxMotionState, boxShape, inertia);
    boxBody = new btRigidBody(boxInfo);
    dynamicsWorld->addRigidBody(boxBody);
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("SeismoSense");

    init();
    
    glutDisplayFunc(display);
    glutTimerFunc(16, update, 0);

    glutMainLoop();
    return 0;
}
