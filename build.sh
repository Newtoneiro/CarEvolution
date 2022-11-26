#!/bin/sh

BUILD_DIR=cmake-build-debug

if [ ! -d "./$BUILD_DIR" ]
then
    cmake -S . -B ./$BUILD_DIR
fi

cmake --build $BUILD_DIR --target CarEvolution -j 9
