cmake_minimum_required(VERSION 3.5)
project(Q10_04_MergeSort)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Q10_04_MergeSort ${SOURCE_FILES})