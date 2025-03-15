DIR="Bin"
PROGRAM="SeismoSense"

clear

# Check if Bullet is installed
# if ! brew list --formula | grep -q "^bullet$"; then
#     echo "Bullet engine not found. Installing..."
#     brew install bullet
#     clear
# else
#     echo "Bullet engine is already installed."
# fi

# Check if GLFW is installed
if ! brew list --formula | grep -q "^glfw$"; then
    echo "OpenGL Tools (GLFW) not found. Installing..."
    brew install glfw
    clear
else
    echo "OpenGL Tools are already installed."
fi

# Make sure a `Bin` folder exists to contain the binaries
if [ ! -d "$DIR" ]; then
    mkdir -p "$DIR"
    echo "Directory $DIR created." 
else
    echo "Directory $DIR found."
fi

# Compilation command
echo "Compiling..."
# g++ -std=c++17 -o $DIR/$PROGRAM main.cpp -I/opt/homebrew/include/bullet -L/opt/homebrew/lib -framework OpenGL -framework GLUT -lBulletDynamics -lBulletCollision -lLinearMath
g++ -std=c++17 -w -o $DIR/$PROGRAM main.cpp Include/Camera/CameraPerspectiveDemo.cpp Include/Meshes/Mesh.cpp Params/GLParams.cpp Include/Input/Input.cpp Params/Logger.cpp Include/Meshes/Matrices.cpp Shaders/ShaderLoader.cpp -lglfw -framework OpenGL

echo "Compilation done."

# Execute binaries
echo "Opening $PROGRAM program..."
./$DIR/$PROGRAM