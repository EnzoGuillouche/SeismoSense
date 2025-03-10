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

# Make sure a `Bin` folder exists to contain the binaries
if [ ! -d "$DIR" ]; then
    mkdir -p "$DIR"
    echo "Directory $DIR created." 
else
    echo "Directory $DIR found."
fi

# Compilation command
g++ -std=c++17 -o $DIR/$PROGRAM main.cpp shader.cpp input.cpp render.cpp -framework OpenGL -lglfw

echo "Compilation done."
echo "Opening $PROGRAM program..."

# Execute binaries
./$DIR/$PROGRAM

# Make sure the build finished normally
echo "Program $PROGRAM terminated without building issues."