cmake_minimum_required(VERSION 3.5)
project(Q16_IntSquare)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Q16_IntSquare ${SOURCE_FILES})