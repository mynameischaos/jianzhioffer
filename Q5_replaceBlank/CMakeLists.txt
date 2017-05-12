cmake_minimum_required(VERSION 3.5)
project(Q5_replaceBlank)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(Q5_replaceBlank ${SOURCE_FILES})