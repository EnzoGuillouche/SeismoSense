#include <vector>
#include "Include/Meshes/Meshes.h"
#include "Include/Camera/CameraPerspectiveDemo.hpp"

using namespace std;

int runCameraPerspectiveDemo(const char* window_name) {
    
    CameraPerspectiveDemo *demo = new CameraPerspectiveDemo();
    
    /**
     *  Generating a cube mesh and adding it to the world:
     *  
     *  - The first parameter is the generated mesh
     *  - The second parameter is the world position
     *  - The third parameter is the world rotation
     */
    
    Mesh mesh;
    mesh.generateCube(2.0f);
    demo->addMesh(mesh, {0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f});
    
    int run = demo->run(window_name);
    delete(demo);
    return run;
}

int main(int argc, const char * argv[]) {
    int run = runCameraPerspectiveDemo("SeismoSense");
    
    return 0;
}
