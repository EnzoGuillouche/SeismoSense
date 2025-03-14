#include <btBulletDynamicsCommon.h>  // Bullet Physics

// Bullet physics world
btDiscreteDynamicsWorld* dynamicsWorld;
btRigidBody* boxBody;

// Initialization
void init() {
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