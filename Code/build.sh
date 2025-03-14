DIR="Bin"
PROGRAM="SeismoSense"

clear

# Check if Bullet is installed
if ! brew list --formula | grep -q "^bullet$"; then
    echo "Bullet engine not found. Installing..."
    brew install bullet
    clear
else
    echo "Bullet engine is already installed."
fi
# Check if freeglut is installed
if ! brew list --formula | grep -q "^freeglut$"; then
    echo "OpenGL Tools not found. Installing..."
    brew install freeglut
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
g++ -std=c++17 -o $DIR/$PROGRAM main.cpp -I/opt/homebrew/include/bullet -L/opt/homebrew/lib -framework OpenGL -framework GLUT -lBulletDynamics -lBulletCollision -lLinearMath

echo "Compilation done."
echo "Opening $PROGRAM program..."

# Execute binaries
./$DIR/$PROGRAM

# Make sure the build finished normally
echo "Program $PROGRAM terminated without building issues."