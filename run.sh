#!/bin/bash

rm -r build

mkdir -p build
g++ main.cpp -o build/main

if [ -f build/main ]; then
    ./build/main < input.txt
else
    echo "Compilation failed"
fi
