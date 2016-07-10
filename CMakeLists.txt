cmake_minimum_required(VERSION 3.5)
project(Algorithm)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES Algorithm/第4章树/二叉查找树/SearchTree.cpp)
add_executable(Algorithm ${SOURCE_FILES})