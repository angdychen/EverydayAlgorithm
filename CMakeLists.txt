cmake_minimum_required(VERSION 3.5)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Algorithm/第三章表ADT/栈/stack.cpp)
add_executable(Algorithm ${SOURCE_FILES})