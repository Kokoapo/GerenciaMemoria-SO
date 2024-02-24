#!/bin/bash

# Compile the C++ code
g++ main.cpp -o bin/main

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executing the program..."

    # Change directory to the bin subdirectory
    cd bin

    # Execute the executable with the given arguments
    echo "4 frames"
    ./main ref1log1 4 0
    ./main ref1log1 4 1
    echo "8 frames"
    ./main ref1log1 8 0
    ./main ref1log1 8 1
    echo "16 frames"
    ./main ref1log1 16 0
    ./main ref1log1 16 1
    echo "32 frames"
    ./main ref1log1 32 0
    ./main ref1log1 32 1
else
    echo "Compilation failed. Exiting..."
fi
