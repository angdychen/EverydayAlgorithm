cmake_minimum_required(VERSION 3.5)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Algorithm/裴波那契数列/Fib.cpp)
add_executable(Algorithm ${SOURCE_FILES})