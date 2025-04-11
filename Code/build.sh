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
g++ -std=c++17 -o $DIR/$PROGRAM main.cpp Include/Shape/shape.cpp -framework OpenGL -lglfw

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation done."
    clear

    # Execute binaries only if compilation was successful
    ./$DIR/$PROGRAM
else
    echo "Compilation failed."
fi