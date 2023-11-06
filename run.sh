#!/bin/bash

if [ -z "$1" ]; then
    echo "Please provide a number as an argument."
    exit 1
fi

NUMBER=$(printf "%02d" $1)

BUILD_DIR="./build/"

PROGRAM=$(find "$BUILD_DIR" -type f -executable -name "${NUMBER}_*.out" -print -quit)

if [ -z "$PROGRAM" ]; then
    echo "No executable found for number $NUMBER."
    exit 1
fi

echo "Running $PROGRAM..."
"$PROGRAM"
echo "Finished running $PROGRAM"
