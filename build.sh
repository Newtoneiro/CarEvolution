#!/bin/sh

BUILD_DIR=build

if [ ! -d "./$BUILD_DIR" ]
then
    cmake -S . -B ./$BUILD_DIR
fi

cmake --build $BUILD_DIR --target Tests -j 9
cmake --build $BUILD_DIR --target CarEvolution -j 9
