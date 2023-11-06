#!/bin/bash

# Define the build directory
BUILD_DIR="./build/"

for program in "${BUILD_DIR}"*; do
    if [[ -x "$program" ]]; then
        echo "Running $program..."
        "$program" 
        echo "Finished running $program"
        echo 
    fi
done

