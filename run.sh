#!/bin/sh
# Compile and run the Library Management System
g++ -std=c++11 -Wall -Wextra main.cpp -o library
if [ $? -eq 0 ]; then
    ./library
else
    echo "Compilation failed. Please check the code."
fi
