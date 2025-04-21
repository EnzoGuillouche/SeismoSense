DIR="Bin"
PROGRAM="seismoSense"

clear

# Check if GLFW is installed
if ! brew list --formula | grep -q "^glfw$"; then
    echo "GLFW not found. Installing..."
    brew install glfw
    clear
else
    echo "GLFW is already installed."
fi

# Check if GLM is installed
if ! brew list --formula | grep -q "^glm$"; then
    echo "GLM not found. Installing..."
    brew install glm
    clear
else
    echo "GLM is already installed."
fi

# Make sure a `Bin` folder exists to contain the binaries
if [ ! -d "$DIR" ]; then
    mkdir -p "$DIR"
    echo "Directory $DIR created." 
else
    echo "Directory $DIR found."
fi

# Compilation command
echo "Compiling the program..."
g++ -std=c++17 -o $DIR/$PROGRAM main.cpp Include/Shape/shape.cpp Include/Shape/triangle.cpp Include/Shape/square.cpp Include/Shape/pyramid.cpp Include/Shape/cube.cpp -framework OpenGL -lglfw -I/opt/homebrew/include -L/opt/homebrew/lib

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation succeeded."
    sleep 1
    clear
    echo "Running $PROGRAM..."
    ./$DIR/$PROGRAM
else
    echo "Compilation failed."
    exit 1
fi
