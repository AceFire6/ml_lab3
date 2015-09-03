cmake_minimum_required(VERSION 3.1)
project(ml_lab3)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES src/main.cpp)
add_executable(ml_lab3 ${SOURCE_FILES} src/Perceptron.cpp src/Perceptron.h)
